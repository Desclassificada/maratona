#include <bits/stdc++.h>

using namespace std;

long int vetor[20010];
long long int soma[20010];
queue<long long int> acumulado;

int main(){
	
	
	int n;
	
	while(scanf("%d", &n) != EOF){	
		soma[0] = 0;
		for(int i=1; i<= n; i++){
			scanf("%ld", vetor+i);
			soma[i] = soma[i-1] + vetor[i];
			acumulado.push(vetor[i]);
		}		

		for(int d=1; d<n;d++){
			for(int i=1; i+d<=n; i++){				
				long long int s = soma[i+d] - soma[i-1];
				long long int ant = acumulado.front();
				acumulado.pop();
				
				acumulado.push(max(s-ant, s-acumulado.front()));
			}
			
			acumulado.pop();
			
		}
		
		printf("%lld\n", acumulado.front());
		
		acumulado.pop();
	}
	
	return 0;
}
