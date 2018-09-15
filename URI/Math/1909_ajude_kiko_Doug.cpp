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
bitset<100010> vis;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,t;
	while(cin >> n >> t){
		if(n == 0 && t == 0)
			break;
		ll acc = 1;
				vis.reset();
		REP(i,0,n){
			ll x;
			cin >> x;
			vis[x] = 1;
			acc = mmc(acc,x);
		}

		bool vdc = false;
		REP(i,2,t+1){
			if(!vis[i]){
				if(mmc(acc,(ll)i) == t){
					cout << i << endl;
					vdc = true;
					break;
				}
			}
		}
		if(vdc){
			continue;
		}else{
			cout << "impossivel" << endl;
		}
	}
	return 0;
}
