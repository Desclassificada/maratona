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
#define cins(a) scanf(" %s", a)
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

char a[100010];
char b[100010];
long int v_0[100010];
long int v_1[100010];
long int v_1_0[100010];
long int v_0_0[100010];

long int n;
ll cont;

int main(){	
	
	cini(n);
	cins(a);
	cins(b);
	
	for(int i=0; i<n; i++){
		v_1[i+1] = v_1[i];
		v_0[i+1] = v_0[i];
		v_1_0[i+1] = v_1_0[i];
		v_0_0[i+1] = v_0_0[i];
		
		if(a[i] == '1')
			 v_1[i+1]++;
		else
			 v_0[i+1]++;
			 
		if( (a[i] == '1') and (b[i] == '0') )
			 v_1_0[i+1]++;
			 
		if( (a[i] == '0') and (b[i] == '0') )
			 v_0_0[i+1]++;
	}
	
	for(int i=1; i<n; i++){
		if(a[i] == '0'){
			if(b[i] == '0'){
				cont += (ll) v_1[i];
			}else{
				cont += (ll) v_1_0[i];				
			}
		}else{
			if(b[i] == '0'){
				cont += (ll) v_0[i];
			}else{
				cont += (ll) v_0_0[i];				
			}			
		}
	}
	
	coutlll(cont);
	
	return 0;
}
