#include <bits/stdc++.h>

using namespace std;

int n;
long long memo[1010];

long long catalan(int x){	
	long long res = 0;
	if(x == 0)
		return 1;
		
	if(memo[x] != -1)
		return memo[x];
		
	for(int i=0; i<x; i++){
		res += catalan(i) *  catalan(x-1-i);
	}
			
	return memo[x] = res;	
}

int main(){
	memset(memo, -1, sizeof(memo));
	
	cin >> n;

	cout << catalan(n) << endl;
	
	return 0;
}







