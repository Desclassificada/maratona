#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN 100010
#define MAXM 
#define endl '\n'

#define cind(a) scanf("%lf", &a)
#define cinc(a) scanf(" %c", &a)
#define cinll(a) scanf("%lld", &a)

#define cin1i(a) scanf("%ld", &a)
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

ll comeco[MAXN];
ll vetor[MAXN];
ll maximo[MAXN];

int main(){	
	long int n, k;
	cin2i(n, k);
	
	for(long int i=0; i<n; i++){
		cinll(vetor[i]);
		vetor[i] *= -1ll;
		
		maximo[i] = -100000000000000ll;
	}
	
	ll op = 0;
	
	for(int i=1; i<=k; i++)
		op += vetor[n-i];

	maximo[n-k] = op;
	comeco[n-k] = op;
	
	for(int i=n-k-1; i>0; i--){
		op += vetor[i] - vetor[i+k];
			
		maximo[i] = max(op, maximo[i+1]);
		comeco[i] = op;
	}
	
	comeco[0] = op + vetor[0] - vetor[k];

	ll res = -100000000000000ll;
	
	for(int i=0; i+2*k<=n; i++){
		res = max(res, comeco[i] + maximo[i+k]);
	}
	
	cout << res << endl;
	
	return 0;
}
