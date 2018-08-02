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

long int n;
ll s;

ll vetor[300100];

/*
ll memo[300010];

ll minimo(long int p){
	if(p >= n)
		return 0ll;
		
	if(memo[p] != -1ll){
		return memo[p];
	}
	
	return memo[p] = min( minimo(p+1) + vetor[p]-vetor[p-1], s + minimo(p+1));
}
*/

int main(){	
 	cini(n);
 	cinll(s);
	
	for(int i=0; i<n; i++){
		cinll(vetor[i]);
	}
	
	sort(vetor, vetor + n);
	
	ll res = s;
	
	for(int p=1;p <n; p++){
		res += min(vetor[p]-vetor[p-1], s);		
	}
	
	coutlll( res );
	
	return 0;
}
