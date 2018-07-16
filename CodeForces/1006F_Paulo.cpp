#include <bits/stdc++.h>

using namespace std;

long long int matriz[22][22], k, res = 0;

unordered_map<long long int, long long int> memo[22][22];

long int n, m;

void inicio(int i, int j, int tam,long long atual){

	memo[i][j][atual]++;
	
	if(tam == (n+m)/2){
		return;
	}
	
	if(i == n){
		inicio(i, j+1, tam+1, atual^ matriz[i][j+1]);
		return;
	}
	if(j == m){
		inicio(i+1, j, tam+1, atual^ matriz[i+1][j]);
		return;
	}

	inicio(i+1, j, tam+1, atual^ matriz[i+1][j]);
	inicio(i, j+1, tam+1, atual^ matriz[i][j+1]);
}

void fim(int i, int j, int tam, long long atual){
		
	if( tam == (n+m)/2){
		res += memo[i][j][atual];
		return;
	}
			
	if(i == 1){
		fim(i, j-1, tam-1, atual^ matriz[i][j]);
		return;
	}
	
	if(j == 1){
		fim(i-1, j, tam-1, atual^ matriz[i][j]);
		return;
	}
	
	fim(i-1, j, tam-1, atual^ matriz[i][j]);
	fim(i, j-1, tam-1, atual^ matriz[i][j]);
}

int main(){
	
	cin >> n >> m  >> k;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> matriz[i][j];
		}
	}
	
	inicio(1, 1, 1, matriz[1][1]);
	fim(n, m, n+m-1, k);
	
	cout << res << endl;
		
    return 0;
}
