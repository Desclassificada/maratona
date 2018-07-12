#include <bits/stdc++.h>

using namespace std;
#define INF 1073741823
char matriz [11][11];
bool visitado[11][11][11][11][11][11];
int n;

struct robo{
	pair<int,int> ben;
	pair<int,int> aneed;
	pair<int,int> cindy;
	int dist;
};

bool valido(int x, int y){
	return x < n && x >= 0 && y < n && y >= 0;
}
bool mover(int x,int y){
	if(valido(x,y) && matriz[x][y] != '#')
		return 1;
	return 0;
}
bool finish(robo atual){
	int cont = 0;
	if(matriz[atual.ben.first][atual.ben.second] == 'X')
		cont++;
	if(matriz[atual.aneed.first][atual.aneed.second] == 'X')
		cont++;
	if(matriz[atual.cindy.first][atual.cindy.second] == 'X')
		cont++;
	return cont == 3;
}
bool mark(robo atual){
	if(visitado[atual.ben.first][atual.ben.second][atual.aneed.first][atual.aneed.second][atual.cindy.first][atual.cindy.second])
		return 1;
	else{
		visitado[atual.ben.first][atual.ben.second][atual.aneed.first][atual.aneed.second][atual.cindy.first][atual.cindy.second] = 1;
		return 0;
	}
}
int bfs(robo inicio){
	queue<robo> fila;
	fila.push(inicio);
	while(!fila.empty()){
		robo atual = fila.front();
		fila.pop();
		if(mark(atual)){
			continue;
		}
		
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++) {
		//		if (atual.aneed.first == i && atual.aneed.second == j) 
		//			printf("A");
		//		else if (atual.ben.first == i && atual.ben.second == j) 
		//			printf("B");
		//		else if (atual.cindy.first == i && atual.cindy.second == j)
		//			printf("C");
		//		else 
		//			printf("%c", matriz[i][j]);
		//}
		//printf("\n");
	  	//}
		
		 
		if(finish(atual))
			return atual.dist;
		atual.dist += 1;
		robo alterar = atual;
		robo aux = atual;
		if(mover(atual.ben.first-1,atual.ben.second)){
			alterar.ben.first = atual.ben.first-1;
			alterar.ben.second = atual.ben.second;
		}
		if(mover(atual.aneed.first-1,atual.aneed.second)){
			alterar.aneed.first = atual.aneed.first-1;
			alterar.aneed.second = atual.aneed.second;
		}
		if(mover(atual.cindy.first-1,atual.cindy.second)){
			alterar.cindy.first = atual.cindy.first-1;
			alterar.cindy.second = atual.cindy.second;
		}	
		aux.aneed = ((alterar.ben == alterar.aneed)  || (alterar.aneed == alterar.cindy)) ?  atual.aneed : alterar.aneed;
		aux.ben = ((alterar.ben == alterar.aneed)  || (alterar.ben == alterar.cindy)) ?  atual.ben : alterar.ben;
		aux.cindy = ((alterar.ben == alterar.cindy)  || (alterar.aneed == alterar.cindy)) ?  atual.cindy : alterar.cindy;
		set<pair<int,int> > conj;
		conj.insert(aux.aneed);
		conj.insert(aux.ben);
		conj.insert(aux.cindy);
		if(conj.size() == 3)
			fila.push(aux);
		
		conj.clear();
		aux = atual;
		alterar = atual;
		if(mover(atual.ben.first,atual.ben.second+1)){
			alterar.ben.first = atual.ben.first;
			alterar.ben.second = atual.ben.second+1;
		}
		if(mover(atual.aneed.first,atual.aneed.second+1)){
			alterar.aneed.first = atual.aneed.first;
			alterar.aneed.second = atual.aneed.second+1;
		}
		if(mover(atual.cindy.first,atual.cindy.second+1)){
			alterar.cindy.first = atual.cindy.first;
			alterar.cindy.second = atual.cindy.second+1;
		}
		aux.aneed = ((alterar.ben == alterar.aneed)  || (alterar.aneed == alterar.cindy)) ?  atual.aneed : alterar.aneed;
		aux.ben = ((alterar.ben == alterar.aneed)  || (alterar.ben == alterar.cindy)) ?  atual.ben : alterar.ben;
		aux.cindy = ((alterar.ben == alterar.cindy)  || (alterar.aneed == alterar.cindy)) ?  atual.cindy : alterar.cindy;
		conj.insert(aux.aneed);
		conj.insert(aux.ben);
		conj.insert(aux.cindy);
		if(conj.size() == 3)
			fila.push(aux);
		
		conj.clear();
		
		alterar = atual;
		aux = atual;
		if(mover(atual.ben.first,atual.ben.second-1)){
			alterar.ben.first = atual.ben.first;
			alterar.ben.second = atual.ben.second-1;
		}
		if(mover(atual.aneed.first,atual.aneed.second-1)){
			alterar.aneed.first = atual.aneed.first;
			alterar.aneed.second = atual.aneed.second-1;
		}
		if(mover(atual.cindy.first,atual.cindy.second-1)){
			alterar.cindy.first = atual.cindy.first;
			alterar.cindy.second = atual.cindy.second-1;
		}
		
		aux.aneed = ((alterar.ben == alterar.aneed)  || (alterar.aneed == alterar.cindy)) ?  atual.aneed : alterar.aneed;
		aux.ben = ((alterar.ben == alterar.aneed)  || (alterar.ben == alterar.cindy)) ?  atual.ben : alterar.ben;
		aux.cindy = ((alterar.ben == alterar.cindy)  || (alterar.aneed == alterar.cindy)) ?  atual.cindy : alterar.cindy;
		conj.insert(aux.aneed);
		conj.insert(aux.ben);
		conj.insert(aux.cindy);
		if(conj.size() == 3)
			fila.push(aux);
		conj.clear();
		aux = atual;
		alterar = atual;
		if(mover(atual.ben.first+1,atual.ben.second)){
			alterar.ben.first = atual.ben.first+1;
			alterar.ben.second = atual.ben.second;
		}
		if(mover(atual.aneed.first+1,atual.aneed.second)){
			alterar.aneed.first = atual.aneed.first+1;
			alterar.aneed.second = atual.aneed.second;
		}
		if(mover(atual.cindy.first+1,atual.cindy.second)){
			alterar.cindy.first = atual.cindy.first+1;
			alterar.cindy.second = atual.cindy.second;
		}
     	aux.aneed = ((alterar.ben == alterar.aneed)  || (alterar.aneed == alterar.cindy)) ?  atual.aneed : alterar.aneed;
		aux.ben = ((alterar.ben == alterar.aneed)  || (alterar.ben == alterar.cindy)) ?  atual.ben : alterar.ben;
		aux.cindy = ((alterar.ben == alterar.cindy)  || (alterar.aneed == alterar.cindy)) ?  atual.cindy : alterar.cindy;
		
		conj.insert(aux.aneed);
		conj.insert(aux.ben);
		conj.insert(aux.cindy);
		if(conj.size() == 3)
			fila.push(aux);
		
		conj.clear();
	}
	return -1;
}
int main() {
	int t;
	cin >> t;
	int cont = 1;
	while(t--){
		cin >> n;
		robo auxiliar;
		memset(visitado,0,sizeof visitado);
		memset(matriz,0,sizeof matriz);
		for(int i = 0; i < n;i++){
			for(int j = 0; j < n;j++){
				cin >> matriz[i][j];
				if(matriz[i][j] == 'A'){
					auxiliar.aneed.first = i;
					auxiliar.aneed.second = j;
					matriz[i][j] = '.';
				}else if(matriz[i][j] == 'B'){
					auxiliar.ben.first = i;
					auxiliar.ben.second = j;
					matriz[i][j] = '.';
				}else if(matriz[i][j] == 'C'){
					auxiliar.cindy.first = i;
					auxiliar.cindy.second = j;
					matriz[i][j] = '.';
				}
			}
		}
		auxiliar.dist = 0;
		cout << "Case " << cont++ << ": ";
		int aux = bfs(auxiliar);
		if(aux == -1){
			cout << "trapped" << endl;
		}else{
			cout << aux << endl;
		}

	}
	return 0;
}
