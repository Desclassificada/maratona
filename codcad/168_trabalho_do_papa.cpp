#include <iostream>
#include <algorithm>

using namespace std;

struct Caixa{
	int p;
	int r;	
};

bool compara(Caixa a, Caixa b){
	if(a.r == b.r)
		return a.p < a.p;
	
	return a.r < b.r;
}

Caixa vetor[1010];
int pd[1010];

int main(){
	int n;
	
	scanf("%d", &n);
	
	for(long int i=0; i < n; i++){
		cin >> vetor[i].p;
		cin >> vetor[i].r;
		
		if(vetor[i].p > vetor[i].r){ // Verificar se a caixa é válida.
			i--;
			n--;
			//se sim, ignora o ultimo valor lido usando i--, e n-- para diminuir a quantidade de caixas.
		}
	}
	
	sort(vetor, vetor + n, compara); // Ordena as caixas com menor resistência e, em caso de empate, pelo menor peso.
	
	for(int i=0; i<=n; i++){
		pd[i] = 0x3f3f3f3f;
	}
	
	pd[0] = 0;
	int maximo = 0;
	
	for(int i=0; i<n; i++){
		for(int q=n; q>=0; q--){
			//pd[q] é o peso da pilha com q caixa
			if( (pd[q] + vetor[i].p) <= vetor[i].r){ // Verificar se é possível colocar a caixa vetor[i] em baixo.
				if( (pd[q]+vetor[i].p) < pd[q+1] ){ // Verificar se é vantajoso atualizar o peso da pilha com q+1 caixas.
					pd[q+1] = pd[q] + vetor[i].p;
					maximo = max(maximo, q+1);
				}
			}
		}
	}
		
	printf("%d\n", maximo);
		
	return 0;
}
