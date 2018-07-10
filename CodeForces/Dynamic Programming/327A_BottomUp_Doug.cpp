#include <bits/stdc++.h>

using namespace std;
#define INF 1073741823
int n;
long long int dp[3][111];
bool vetor[110];


int main() {
	cin >> n;
	int one = 0;
	for(int i = 1;i <= n;i++){
		cin >> vetor[i];
		if(vetor[i])
			one++;
	}
	for(int ind = 1; ind <= n;ind++){
		dp[0][ind] = dp[0][ind-1] + vetor[ind];
		dp[1][ind] = max(dp[0][ind-1],dp[1][ind-1]) + !vetor[ind];
		dp[2][ind] = max(dp[1][ind-1],dp[2][ind-1]) + vetor[ind];
	}
	if(n == one)
		cout << n - 1 << endl;
	else 
		cout << max(dp[0][n],max(dp[1][n],dp[2][n])) << endl;
	return 0;
}

