#include <bits/stdc++.h>

using namespace std;
long int vetor[100100];

int main(){
	long int n, cont = 0;
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> vetor[i];
	}
	
	sort(vetor, vetor + n);
	
	int maior = n-1;
	int menor = n-2;
	
	while(maior > 0){
		while(menor >=0 and vetor[menor] >= vetor[maior]){
			menor--;
		}
		
		if(menor >= 0){
			maior--;
			menor--;
			cont++;
		}else{
			break;
		}
	}
	

	cout << cont << endl;

	return 0;
}
