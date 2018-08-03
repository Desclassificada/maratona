#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN 50010
#define MAXM 500010
#define endl '\n'

#define cind(a) scanf("%lf", &a)
#define cinc(a) scanf(" %c", &a)
#define cinll(a) scanf("%lld", &a)

#define cini(a) scanf("%ld", &a)
#define cin2i(a, b) scanf("%ld %ld", &a, &b)
#define cin3i(a, b, c) scanf("%ld %ld %ld", &a, &b, &c)
#define cin4i(a, b, c, d) scanf("%ld %ld %ld %ld", &a, &b, &c, &d)
#define cin5i(a, b, c, d, e) scanf("%ld %ld %ld %ld %ld", &a, &b, &c, &d, &e)

#define coutd(a) printf("%lf", a)
#define coutdl(a) printf("%lf\n", a)
#define coutc(a) printf("%c", a)
#define coutcl(a) printf("%c\n", a)
#define coutll(a) printf("%lld", a)
#define coutlll(a) printf("%lld\n", a)

#define couti(a) printf("%ld", a)
#define coutil(a) printf("%ld\n", a)
#define cout2i(a, b) printf("%ld %ld\n", a, b)
#define cout3i(a, b, c) printf("%ld %ld %ld\n", a, b, c)
#define cout4i(a, b, c, d) printf("%ld %ld %ld %ld\n", a, b, c, d)
#define cout5i(a, b, c, d, e) printf("%ld %ld %ld %ld %ld\n", a, b, c, d, e)

using namespace std;

typedef long long int ll;
typedef pair<long int, long int> pii;

char s[1010];
char t[1010];
long int n, m, q;
bool vetor[1010];

int main(){	
	cin3i(n, m, q);
	scanf(" %s", s);
	scanf(" %s", t);

	if(n >=m )
	for(int i=0; i < n-m+1; i++){
		vetor[i] = true;
		for(int j=0; j < m; j++){
			if(s[i+j] != t[j]){
				vetor[i] = false;
				break;
			}
		}
	}
	
	for(int i=0; i<q; i++){
		long int a, b;
		cin2i(a, b);
		
		long int cont = 0;
		long int p = 0;
		a--;
		
		while(a+p+m <= b){
			if(vetor[a+p]){				
				cont++;
			}
			p++;
			
		}
		
		coutil(cont);
	}
	
	return 0;
}
