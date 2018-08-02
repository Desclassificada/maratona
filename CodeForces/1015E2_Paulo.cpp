#include <bits/stdc++.h>
#define INF 3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN
#define MAXM

typedef long long int ll;

using namespace std;

struct Aux{
	int x, y;
	int t;
	Aux(){
	
	}
	Aux(int a, int b, int c){
		x = a;
		y = b;
		t = c;
	}	
};

char matriz[1010][1010];
int aux[1010][1010];
int soma1[1010][1010];
int soma2[1010][1010];

int n, m;

Aux vetor[1000010];
int size;

int main(){
	
	scanf("%d %d", &n, &m);
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf(" %c", &matriz[i][j]);
		}
	}

	for(int i=1; i<=n; i++){
		int soma = 0;
		for(int j=1; j<=m; j++){
			if(matriz[i][j] == '.'){
				soma=0;
			}
			
			aux[i][j] = soma;
			
			if(matriz[i][j]== '*')
				soma += 1;
		}
	}
	
	for(int i=1; i<=n; i++){
		int soma = 0;
		for(int j=m; j>=1; j--){
			if(matriz[i][j] == '.'){
				soma=0;
			}
			
			aux[i][j] = min(soma, aux[i][j]);
			
			if(matriz[i][j]== '*')
				soma += 1;
		}
	}
	
	for(int i=1; i<=m; i++){
		int soma = 0;
		for(int j=1; j<=n; j++){
			if(matriz[j][i] == '.'){
				soma=0;
			}
			
			aux[j][i] = min(soma, aux[j][i]);
			
			if(matriz[j][i]== '*')
				soma += 1;
		}
	}
	
	for(int i=1; i<=m; i++){
		int soma = 0;
		for(int j=n; j>=1; j--){
			if(matriz[j][i] == '.'){
				soma=0;
			}
			
			aux[j][i] = min(soma, aux[j][i]);
			
			if(matriz[j][i]== '*')
				soma += 1;
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(aux[i][j] > 0){
				register int a = aux[i][j];
				vetor[size++] = Aux(i,j, a);
				
				soma1[i][j-a] += 1; 						
				soma1[i][j+a+1] -= 1; 				
								
				soma2[i-a][j] += 1; 				
				soma2[i+a+1][j] -= 1; 												
			}
		}
	}

	for(int i=0; i<=n; i++){
		for(int j=1; j<=m; j++){
			soma1[i][j] += soma1[i][j-1];
		}
	}
	
	for(int i=0; i<=m; i++){
		for(int j=1; j<=n; j++){
			soma2[j][i] += soma2[j-1][i];
			
			if(soma1[j][i] or soma2[j][i])
				matriz[j][i] = 1;
			else if(matriz[j][i] == '*'){
				puts("-1\n");
				return 0;					
			}
		}
	}

	printf("%d\n", size);
	
	for(int i=0; i<size; i++){
		printf("%d %d %d\n", vetor[i].x, vetor[i].y, vetor[i].t);
	}
	
	return 0;
}
