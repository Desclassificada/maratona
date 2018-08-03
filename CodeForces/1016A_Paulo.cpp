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

int main(){	
	long int n, m;
	long int mod = 0;
	
	cin2i(n, m);
	
	long int aux;
	cini(aux);
	couti(aux/m);
	mod += aux%m;
	mod = (mod%m);
	
	for(int i=1; i<n; i++){
		long int aux;
		cini(aux);
		
		coutc(' ');
		couti((aux+mod)/m);
		
		mod = (aux+mod)%m;
		mod = (mod%m);
	}
	
	coutc('\n');
	
	return 0;
}
