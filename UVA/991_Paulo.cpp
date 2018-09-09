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

long long memo[20];

long long catalan(int n){
	if(n == 0)
		return 1LL;
			
	if(memo[n] != -1LL)
		return memo[n];
		
	return memo[n] = (2LL*(2LL*n - 1)*catalan(n-1))/(n+1LL);
}

int main(){		
	
	memset(memo, -1, sizeof(memo) );
	
	int n;
	bool t = false;

	while(cin >> n){
		if(t)
			cout << endl;			
			
		cout << catalan(n) << endl;
		t = true;
	}
	
	return 0;
}

