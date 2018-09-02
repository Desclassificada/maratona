#include <bits/stdc++.h>

using namespace std;

int n, k;
long long memo[1010][1010];

long long res(int bit, int uns){
	if(uns == k)
		return 0ll;
	if(bit == n)
		return 1ll;
		
	if(memo[bit][uns] != -1ll)
		return memo[bit][uns];
	
	return memo[bit][uns] = (res(bit+1, 0) + res(bit+1, uns+1))%1000000007ll;	
}

int main(){
	memset(memo, -1, sizeof(memo));
	
	cin >> n >> k;

	cout << res(0, 0) << endl;
	
	return 0;
}






