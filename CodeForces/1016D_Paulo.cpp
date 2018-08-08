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

long int matriz[110][110];
long int a[110];
long int b[110];
long int n, m;
int main(){	
	long int ac_a = 0, ac_b = 0;
	long c = 0;
	
	cin2i(n, m);
	for(int i=0; i<n; i++){
		cini(a[i]);
		ac_a ^= a[i];
		matriz[i][m-1] = a[i];
	}
	for(int i=0; i<m; i++){
		cini(b[i]);
		ac_b ^= b[i];
		matriz[n-1][i] = b[i];
	}
	
	ac_a ^= a[n-1];
	ac_b ^= b[m-1];
	
	c = ac_a ^ b[m-1];
	
	if(c == (ac_b ^ a[n-1])){
		puts("YES\n");
		
		matriz[n-1][m-1] = c;
		 
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				couti(matriz[i][j]);
				coutc(' ');
			}
			
			coutc('\n');
		}
	}else{
		puts("NO\n");
	}
	
	return 0;
}
