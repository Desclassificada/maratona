#include <bits/stdc++.h>

using namespace std;
bool matriz[7][7];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool ok(int a,int b){
	if(matriz[a][b] == 1)
		return 0;
	queue<pair<int,int> > fila;
	fila.push(make_pair(a,b));

	while(!fila.empty()){
		pair <int,int> aux = fila.front();

		fila.pop();
		matriz[aux.first][aux.second] = 1;
		for(int i = 0;i < 4;i++){
			int x = aux.first + dx[i];
			int y = aux.second + dy[i];
			if(x == 5 && y == 5)
					return 1;
			if(matriz[x][y] == 0)
				fila.push(make_pair(x,y));
		}
	}
	return 0;
}
int main(){
    int n;
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--){
    	memset(matriz,1,sizeof matriz);
    	for(int i = 1;i<=5;i++){
    		for(int j = 1;j<=5;j++){
    			cin >> matriz[i][j];
    		}
    	}
    	/*for(int i = 0;i<7;i++){
			for(int j = 0;j<7;j++){
				cout << matriz[i][j] << " ";
			}
			cout << endl;
		}*/
    	if(ok(1,1)){
			cout << "COPS" << endl;
		}else{
			cout << "ROBBERS" << endl;
		}
    }

    return 0;
}

