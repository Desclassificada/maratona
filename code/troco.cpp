#include <bits/stdc++.h>

using namespace std;

int moedas[] = {3, 6, 20, 50, 100};
int memo[5][1000010];

int troco(int i, int valor){
	if(i == 5)
		return 0x3f3f3f3f;

	if(valor == 0)
		return 0;
	
	if(memo[i][valor] != -1)
		return memo[i][valor];
		
	int nao_colocar = troco(i+1, valor);
	
	if(valor < moedas[i])
		return memo[i][valor] = nao_colocar;
		
	int colocar = 1 + troco(i, valor - moedas[i]);
	
	return memo[i][valor] = min( colocar, nao_colocar );
}

int main(){
	int valor;
	memset(memo, -1, sizeof(memo));
	
	cin >> valor;
	
	cout << troco(0, valor) << endl;	
	
	return 0;
}






