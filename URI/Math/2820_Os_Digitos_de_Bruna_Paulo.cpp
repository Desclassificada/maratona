#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define MOD 1000000007ll
#define ORDEM 3

#define MP make_pair
#define PB push_back
#define F first
#define S second

#define MAXN 100010
#define MAXM 
#define endl '\n'

typedef long long int ll;
typedef pair<long int, long int> pii;
char digit[10];

int main(){		
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int t;
	cin >> t;
	
	while(t--){	
		int n, d = 1;
		ll k;
		cin >> n;
		for(int i=0; i<n; i++)
			cin >> digit[i];
		
		sort(digit, digit + n);
			
		cin >> k;
		k--;
			
		for(ll i=n; i<=k; i*=(ll)n){
			k -= i;
			d++;
		}
		
		string ans;
		
		while(d--){
			ans += digit[k%(ll)n];
			k = k/(ll)n;
		}
		
		reverse(ans.begin(), ans.end());
		
		cout << ans << endl;
	}
	
	return 0;
}
