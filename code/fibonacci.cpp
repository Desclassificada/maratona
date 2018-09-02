#include <bits/stdc++.h>

using namespace std;
long long memo[1010];

long long fib(int n){
	if(memo[n] != -1)
		return memo[n];
	
	if(n <= 1)
		return memo[n] = 1ll;
	else
		return memo[n] = (fib(n-1) + fib(n-2))%1000000007ll;
}

int main(){
	int n;
	
	memset(memo, -1, sizeof(memo));
	
	cin >> n;
	
	cout << fib(n) << endl;
	
	return 0;
}
