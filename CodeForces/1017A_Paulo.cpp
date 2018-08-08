#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<long int, null_type, less<long int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

/*
	o.find_by_order(index)
	o.order_of_key(value)	
	o.find(value)
*/

#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f

#define MP make_pair
#define PB push_back
#define F first
#define S second

#define MAXN 1000100
#define MAXM 
#define endl '\n'

#define cinc(a) scanf(" %c", &a)
#define cinll(a) scanf("%lld", &a)

#define cini(a) scanf("%ld", &a)
#define cin2i(a, b) scanf("%ld %ld", &a, &b)
#define cin3i(a, b, c) scanf("%ld %ld %ld", &a, &b, &c)
#define cin4i(a, b, c, d) scanf("%ld %ld %ld %ld", &a, &b, &c, &d)
#define cin5i(a, b, c, d, e) scanf("%ld %ld %ld %ld %ld", &a, &b, &c, &d, &e)

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

#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)*(b))/__gcd((a), (b)))

typedef long long int ll;
typedef pair<long int, long int> pii;

pii vetor[1010];

int compara(pii a, pii b){
	if(a.F == b.F)
		return a.S < b.S; 
		
	return a.F > b.F;
}

int main(){	
	
	long n;
	cini(n);
	
	for(int i=1; i<=n; i++){
		long a, b, c, d;
		cin4i(a, b, c, d);
		
		vetor[i] = pii(a+b+c+d, i);
	}
	
	sort(vetor+1, vetor+n+1, compara);
	
	for(int i=1; i<=n; i++){
		if(vetor[i].S == 1){
			coutil((long)i);
			return 0;
		}			
	}
	
	return 0;
}
