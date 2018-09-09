#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii > vpi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)*(b))/__gcd((a), (b)))

ll memo[50];

ll dp(int n){
	if(n < 0)
		return 0LL;
	if(n == 0)
		return 1LL;
	if(n == 1)
		return 1LL;
	
	if(memo[n] != -1LL)
		return memo[n];
		
	return memo[n] = 4LL*dp(n-2) + 2LL*dp(n-3) + dp(n-1);
	
}
int main() {
	memset(memo, -1, sizeof(memo));
	
	dp(40);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		cout << dp(n) << endl;	
	}
	
	return 0;
}
