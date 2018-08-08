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

#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)*(b))/__gcd((a), (b)))

typedef long long int ll;
typedef pair<long int, long int> pii;

long int v[MAXN];
long int v2[MAXN];
long int res[MAXN];
long int size = 0;

long int f(long int a, long int b){
	if(a > b)
		return a-1;
		
	return a;
}

int main(){	
	long int n;
	cini(n);
	
	for(int i=1; i<=n; i++)
		cini(v[i]);
		
	for(int i=1; i<n; i++)
		cini(v2[i]);
	v[0] = -1;
	bool ant = false;	
	for(int i=1; i<=n; i++){
		if( abs(v[i]-v[i-1]) == 1){
			if(ant)
				res[size++] = v[i];
			goto continuar;
		}
		
		for(int j=1; j<i; j++){
			if( f(v[j], v[i]) != v2[j]){
				ant = false;
				goto continuar;
			}
		}
					
		for(int j=i+1; j<=n; j++){
			if( f(v[j], v[i]) != v2[j-1]){
				ant = false;
				goto continuar;
			}
		}
		
		ant = true;
		res[size++] = v[i];
		
		continuar:
			continue;
		
	}
	
	sort(res, res + size);
	
	for(int i=0; i<size; i++){
		couti(res[i]);
		coutc(' ');
	}
	
	coutc('\n');
		
	return 0;
}
