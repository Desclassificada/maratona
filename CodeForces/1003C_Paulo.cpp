#include <bits/stdc++.h>

using namespace std;

long int vetor[5100];

int main(){
	long int n, k;
	long double maior = 0;
	
	cin >> n >> k;
	
	for(long int i=1; i<=n; i++){
		cin >> vetor[i];
		
		vetor[i] += vetor[i-1];
 	}
 	
 	for(long int t=k; t <=n; t++){
		for(long int i=1; i+t-1 <= n; i++){
			long double x = ((long double)vetor[i+t-1] - vetor[i-1])/(long double)t;
			
			if(x > maior)
				maior = x;
		}
	}
	
	cout.precision(14);
	cout << fixed;	
	cout << maior << endl;
	
	return 0;
}
