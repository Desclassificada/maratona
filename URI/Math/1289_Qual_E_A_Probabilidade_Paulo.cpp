#include <bits/stdc++.h>

using namespace std;
							// Typedef's  start //
typedef long long   ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii > vpi;

							//	Typedef's end //
							//	Define's start //
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < (b); i++)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)*(b))/__gcd((a), (b)))

							// Define's end //


int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int t;
	
	cin >> t;
	while(t--){
		long int  n, i;
		double p, q, res = 0.0;
		
		cin >> n >> p >> i;
		
		q = 1 - p;
		
		if( p > 1e-8){
			double a0 = pow(q, i-1)*p;
			double r = pow(q, n);
		
			res = a0/(1.0-r);
		}
		
		
		printf("%.4f\n",res);
		
	}
	return 0;
}
