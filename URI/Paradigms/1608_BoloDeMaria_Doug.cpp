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
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	vi item;
	vi bolos;
	while(t--){
		int cash,types,itens;
		cin >> cash >> itens >> types;
		item.resize(itens);
		REP(i,0,itens){
			cin >> item[i];
		}
		int best = 0;
		REP(i,0,types){
			int n;
			cin >> n;
			int need = 0;
			REP(i,0,n){
				int x,y;
				cin >> x >> y;
				need += y*item[x];
			}
			best = max(best,cash/need);
		}
		cout << best << endl;
	}
	return 0;
}
