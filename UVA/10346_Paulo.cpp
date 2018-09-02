#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define MOD 1000000007ll

#define MP make_pair
#define PB push_back
#define F first
#define S second

#define MAXN 100010
#define MAXM 
#define endl '\n'

typedef long long int ll;
typedef pair<long int, long int> pii;

int main(){		
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	ll n, k;
	
	while(cin >> n >> k){
		ll res = 0;
		ll b = 0;
		
		res += n;

		while(n){
			b += n;
			n = b/k;
			b -= n*k;
			res += n;
		}
		
		
		cout << res << endl;
	}
		
	return 0;
}
