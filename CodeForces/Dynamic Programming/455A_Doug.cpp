#include <bits/stdc++.h>

using namespace std;
#define INF 1073741823
long long int dp[100100];
long long int vetor[100100];
long long int solve(int x){
	if(x == 1)
		return dp[1] = vetor[1];
	if(x == 0)
		return dp[0] = 0;
	if(dp[x]>=0)
		return dp[x];
	return dp[x] = max(solve(x-1),solve(x-2)+vetor[x]*x);
}
int main() {
	int x,n;
	cin >> n;
	int maxi = 0;
	memset(dp,-1,sizeof dp);
	for(int i = 0; i< n;i++){
		cin >> x;
		vetor[x]++;
		maxi = max(maxi,x);
	}
	cout << solve(maxi) << endl;
	return 0;
}

