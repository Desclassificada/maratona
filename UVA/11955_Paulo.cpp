#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define MOD 10000l

#define MP make_pair
#define PB push_back
#define F first
#define S second

#define MAXN 100010
#define MAXM 
#define endl '\n'

typedef long long int ll;
typedef pair<long int, long int> pii;

long long memo[60][60];

long long comb(int n, int k){
	if(k == 0)
		return 1LL;
	if(n == k)
		return 1LL;
	
	if(memo[n][k] != -1LL)
		return memo[n][k];
		
	return memo[n][k] = comb(n-1, k) + comb(n-1, k-1);
}

int main(){		
//	cin.tie(0);
//	cin.sync_with_stdio(0);
	
	memset(memo, -1, sizeof(memo) );
	
	int t;
	cin >> t;
	
	for(int x=1; x<=t; x++){	
		string text, a, b;
		cin >> text;
		
		int i = 1;
		
		for(; text[i] != '+'; i++)
			a += text[i];		
		i++;
		for(; text[i] != ')'; i++)
			b += text[i];
		i+=2;
		
		int k = stoi(text.substr(i));
		
		string ans;

		for(i=0; i<=k; i++){
			ans += ((comb(k, i) > 1)? (to_string(comb(k, i)) + "*") : "");
			ans += (((k-i) >= 1)? a: "") + (((k-i)>1) ? ("^"+to_string(k-i)): "");
			ans += (((k-i) >= 1) and (i >= 1)) ? "*" : "";			
			ans += ((i >= 1)? b:"") + ((i>1)? ("^"+ to_string(i)): "");
			ans += (i < k)? "+": "";	
		}
		
		cout << "Case "<< x << ": " << ans << endl;
	}

	return 0;
}
