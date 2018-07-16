#include <bits/stdc++.h>

using namespace std;

int pos_atual = 0;
pair<int, int> pos[200100];
vector<int> grafo[200100];
bool processado[200100];
long int vetor[200100];

void bfs(long int v){
	processado[v] = true;
	vetor[pos_atual] = v;
	pos[v].first = pos_atual++;
	
	for(int u : grafo[v]){
		if(!processado[u])
			bfs(u);		
	} 
	
	pos[v].second = pos_atual;
}

int main(){
	long int n, m;
	
	cin >> n >> m;
	
	for(int i=2; i<=n; i++){
		long int x;
		cin >> x;		
		grafo[x].push_back(i);
	}
	
	bfs(1);
	for(int i=0; i<m; i++){
		long int a, b;
		cin >> a >> b;
		
		if((pos[a].second-pos[a].first) >= b){
			cout << vetor[pos[a].first+b-1] << endl;
		}else{
			cout << "-1" << endl;
		}
	}
		
    return 0;
}

