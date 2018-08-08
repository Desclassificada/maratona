#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<long int, null_type, less<long int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

/*
	o.find_by_order(index)
	o.order_of_key(value)	
	o.find(value)
*/

#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f

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

#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)*(b))/__gcd((a), (b)))

typedef long long int ll;
typedef pair<long int, long int> pii;

long int n, p;

long int matriz[510][510];
long int ac[510][510];

long int sum(int a, int b, int x, int y){
	
	return ac[x][y] - ac[x][b-1] - ac[a-1][y] + ac[a-1][b-1];
}

int main(){		
	
	cin2i(n, p);
	
	for(int i=0; i<p; i++){
		long int a, b;
		cin2i(a, b);
		
		matriz[a][b] = 501;
		ac[a][b] = 501;
	}
	
	for(int i=0; i<p; i++){
		long int a, b;
		cin2i(a, b);
		
		matriz[a][b] = 502;
		ac[a][b] = 502;
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			ac[i][j] += ac[i-1][j];
		}
	}

	for(int j=1; j<=n; j++){
		for(int i=1; i<=n; i++){
			ac[i][j] += ac[i][j-1];
		}
	}
	
	long int p=0, b=0; 
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int t=0; max(i,j)+t<=n; t++){			
				int r = sum(i, j, i+t, j+t);
				
				if(r == 0)
					continue;
				else if((r%501)==0)
					p++;
				else if((r%502)==0)
					b++;
				else
					break;
			}
		}
	}
	
	cout2i(p, b);
	
	return 0;
}
