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

long int memo[100010][3][2][2];
long int n;
string s;

long int solve(long int i, int sum, bool odd, bool zero){
	if(i == n){
		if( (sum == 0) and !odd)
			return 0;
		else
			return INF;
	}
	
	if(memo[i][sum][odd][zero] != -1)
		return memo[i][sum][odd][zero];
		
	if( zero and (s[i] == '0') )
		return memo[i][sum][odd][zero] = 1 + solve(i+1, sum, odd, zero);
	else
		return memo[i][sum][odd][zero] = min( solve(i+1, (sum+(s[i]-'0'))%3, (s[i]-'0')%2, false), 1 + solve(i+1, sum, odd, zero));

}

int main() {
	int t;
	cin >> t;
	while(t--){
		memset(memo, -1, sizeof memo);
		cin >> s;
		n = s.size();
		
		long int res = solve(0, 0, 0, 1);
		int zero = 0;
		
		for(char c : s)
			if(c == '0')
				zero++;
				
		if(res == n){
			if(zero)
				cout << n-1 << endl;
			else
				cout << "Cilada" << endl;		
		}else{
			cout << res << endl;
		}
	}
	
	return 0;
}
