#include <bits/stdc++.h>

using namespace std;

int vetor[11];

int main(){

	int n, soma = 0;
	cin >> n;
	
	for(int i=1; i<=n; i++){
		cin >> vetor[i];		
		soma += vetor[i];
	}
	
	int cont = 1;
	
	while((cont <= n) and ( (2*vetor[cont]) == soma)){
		cont++;		
	}
	
	if(cont == n+1 || n == 1){
		cout << "-1" << endl;
	}else{
		cout << "1" << endl;
		cout << cont << endl;
	}

	return 0;
}
close
