#include <bits/stdc++.h>

using namespace std;
#define INF 1073741823
int dp[4010];
int main() {
	int n;
	vector<int> moedas(3);
	cin >> n >> moedas[0] >> moedas[1] >> moedas[2];
	for(auto atual : moedas){
		for(int i = atual;i <= n;i++){
			dp[i] = max(dp[i],i-atual == 0 || dp[i-atual] >= 1 ? dp[i-atual] + 1 : 0);
		}
	}
	cout << dp[n] << endl;
	return 0;
}

