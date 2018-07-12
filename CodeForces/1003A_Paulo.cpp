#include <bits/stdc++.h>

using namespace std;

int vetor[110];

int main(){

	int n, maior = 0;
	cin >> n;
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		
		vetor[x]++;
	}
	
	for(int i=1; i<=100; i++){
		if(vetor[i] > maior)
			maior = vetor[i];
	}

	cout << maior << endl;

	return 0;
}
