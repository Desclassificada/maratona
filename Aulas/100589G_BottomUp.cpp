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
ll dp[1<<16][16];
int n,k;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		memset(dp,0,sizeof dp);
		REP(i,0,16){
			dp[0][i] = 1LL;
		}

		int tam = 1 << n;
		REP(mask,1,tam){
			REP(i,0,n){
				if(mask & 1 << i)
					REP(ultimo,1,n+1){
						if(abs(ultimo - (i+1)) <= k){
							dp[mask][ultimo] += dp[mask & ~(1<<i)][i+1];
						}
					}
			}
		}
		ll ans = 0;
		REP(i,0,n){
			ans += dp[(tam-1) & ~(1<<i)][i+1];
		}
			cout << ans  << endl;
	}
	return 0;
}
