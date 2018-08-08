#include <bits/stdc++.h>

using namespace std;

long int vetor[20010];
long long int soma[20010];
deque<long long int> acumulado;

int main(){
		
	int n;
	
	while(scanf("%d", &n) != EOF){	
		soma[0] = 0;
		for(int i=1; i<= n; i++){
			scanf("%ld", vetor+i);
			acumulado.push_back(vetor[i]);
		}	
			
		for(int i=1; i<n; i++){				
			acumulado.push_back(max(vetor[i], vetor[i+1]));			
		}
		
		for(int d=2; d<n;d++){
			for(int i=1; i+d<=n; i++){				
				long long int maximo = 0;
				
				maximo = max(maximo, vetor[i+d]+acumulado[0]);
				maximo = max(maximo, vetor[i+d]+acumulado[1]);
				maximo = max(maximo, vetor[i]+acumulado[1]);
				maximo = max(maximo, vetor[i]+acumulado[2]);
				
				acumulado.push_back(maximo);
				acumulado.pop_front();
			}
			
			acumulado.pop_front();
			acumulado.pop_front();
			
		}
		
		printf("%lld\n", acumulado.back());
		
		acumulado.clear();
	}
	
	return 0;
}
