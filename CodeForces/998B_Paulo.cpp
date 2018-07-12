#include <bits/stdc++.h>

using namespace std;

int vetor[110];
int ip[110];
int memo[110][110];

int n, m;

int res(int pos, int moeda){
	if(moeda == 0)
		return 0;
		
	if(pos == n)
		return 0;
		
	if(memo[pos][moeda] != -1)
		return memo[pos][moeda];
		
	if(ip[pos] == 0){
		int v = abs( vetor[pos] - vetor[pos+1]);
		
		if(moeda >= v)
			return memo[pos][moeda] = max(res(pos+1, moeda - v) + 1, res(pos+1, moeda));
	}
	
	return memo[pos][moeda] = res(pos+1, moeda);
}

int main(){

	memset(memo, -1, sizeof(memo));
	
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){
		cin >> vetor[i];
		
		if(vetor[i] % 2 == 0)
			ip[i] = 1;
		else
			ip[i] = -1;
			
		ip[i] += ip[i-1];			
	}
	
	cout << res(1, m) << endl;

	return 0;
}
