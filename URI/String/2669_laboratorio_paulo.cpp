#include <bits/stdc++.h>

#define MAXN 8388608

using namespace std;

const double PI = acos(0) * 2;

struct complex_t{
  double a {0.0}, b {0.0};
  complex_t(){}
  complex_t(double na):a{na}{}
  complex_t(double na, double nb) : a{na}, b{nb}{}
  const complex_t operator+(const complex_t &c) const {
    return complex_t(a + c.a, b + c.b);
  }
  const complex_t operator-(const complex_t &c) const {
    return complex_t(a - c.a, b - c.b);
  }
  const complex_t operator*(const complex_t &c) const {
    return complex_t(a*c.a - b*c.b, a*c.b + b*c.a);
  }
};


typedef complex_t base;

base a[MAXN], b[MAXN];

void fft (base a[], int n, bool invert) {
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w = w * wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i){
			a[i].a = a[i].a / n;
			a[i].b = a[i].b / n;
		}
} 

void multiply (size_t size) {
			
	size_t n = 1, lg_n = 0;
	while(n < size) n <<= 1, lg_n++;
	
	fft (a, n, false),  fft (b, n, false);
	
	for (size_t i=0; i<n; ++i)
		a[i] = a[i] * b[i];
		
	fft (a, n, true);
 
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
	int soma=0;
	string texto;
	cin >> texto;
	
	for(char i : texto)
		soma += (i - 'a' + 1);
		
	size_t size = soma*2 + 1;
	
	int s = 0;
	
	for(int i = 0; i < (int)texto.size(); i++){
		s += (texto[i] - 'a' + 1);
		a[s] = base(1, 0);
	}
	
	s = 0;
		
	b[soma] = base(1, 0);
	
	for(int i = 0; i < (int)texto.size() - 1; i++){
		s += (texto[i] - 'a' + 1);
					
		b[soma - s] = base(1, 0);
	}

	multiply(size);
	
	long int cont = 0;
	
	for(int i=soma+1; i <= 2*soma; i++){
		if( int(a[i].a + 0.5) > 0)
			cont++;
	}
	
	cout << cont << endl;
	
	return 0;
}
