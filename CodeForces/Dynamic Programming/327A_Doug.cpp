#include <bits/stdc++.h>

using namespace std;
#define INF 1073741823
int n;
long long int dp[3][111];
bool vetor[110];
int solve(int ok, int ind){
	if(ind == n)
		return 0;
	if(dp[ok][ind] >= 0)
		return dp[ok][ind];
	if(ok == 1)
		return dp[ok][ind] = max(!vetor[ind] + solve(1,ind+1),vetor[ind] + solve(2,ind+1));
	if(ok == 2)
		return dp[ok][ind] = vetor[ind] + solve(2,ind+1);
	int sol_a = vetor[ind] + solve(0,ind+1);
	int sol_b = !vetor[ind] + solve(1,ind+1);
	return dp[ok][ind] = max(sol_a,sol_b);
}
int main() {
	cin >> n;
	int one = 0;
	for(int i = 0;i < n;i++){
		cin >> vetor[i];
		if(vetor[i])
			one++;
	}
	memset(dp,-1,sizeof dp);
	if(n == one)
		cout << n - 1 << endl;
	else 
		cout << solve(0,0) << endl;
	return 0;
}

