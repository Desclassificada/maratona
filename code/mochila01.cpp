#include <bits/stdc++.h>

using namespace std;

int capacidade;

int pesos[] = {10, 5, 20, 1, 3};
int valores[] = {100, 2, 30, 2, 5}; 
int memo[1010][1010];

int mochila(int i, int p){
	
	if(i == 5)
		return 0;
		
	if(p == capacidade)
		return 0;
	
	if(memo[i][p] != -1)
		return memo[i][p];
	
	if(p+pesos[i] <= capacidade){
		int colocar = mochila(i+1, p + pesos[i]) + valores[i];
		int nao_colocar = mochila(i+1, p);
		
		return memo[i][p] = max(colocar, nao_colocar);
	}else{
		int nao_colocar = mochila(i+1, p);
		
		return memo[i][p] = nao_colocar;
	}
		 
}

int main(){
	memset(memo, -1, sizeof(memo));
	
	cin >> capacidade;

	cout << mochila(0, 0) << endl;
	
	return 0;
}
