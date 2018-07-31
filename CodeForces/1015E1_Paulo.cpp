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
	
	Aux(int a, int b, int c){
		x = a;
		y = b;
		t = c;
	}	
};

char matriz[110][110];
int n, m;

bool res(int i, int j, int t){
	if(((i+t) > n) or ((i-t) < 1) or ((j-t) <1) or ((j+t)>m))
		return false;
		
	bool ver = false;
	
	for(int k=i; k<=i+t; k++){
		if(matriz[k][j] == '.')
			return false;
		if(matriz[k][j] == '*'){
			ver = true;
		}
	}
	
	for(int k=j; k<=j+t; k++){
		if(matriz[i][k] == '.')
			return false;
		if(matriz[i][k] == '*'){
			ver = true;
		}
	}

	for(int k=i; k>=i-t; k--){
		if(matriz[k][j] == '.')
			return false;
		if(matriz[k][j] == '*'){
			ver = true;
		}
	}
	
	for(int k=j; k>=j-t; k--){
		if(matriz[i][k] == '.')
			return false;
		if(matriz[i][k] == '*'){
			ver = true;
		}
	}

	
	return ver;
}

void marcar(int i, int j, int t){
	
	for(int k=i; k<=i+t; k++){
		matriz[k][j] = '#';
	}
	
	for(int k=i; k>=i-t; k--){
		matriz[k][j] = '#';
	}
	
	for(int k=j; k<=j+t; k++){
		matriz[i][k] = '#';
	}
	
	for(int k=j; k>=j-t; k--){
		matriz[i][k] = '#';
	}
}


vector<Aux> vetor;

int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> matriz[i][j];
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			for(int k=100; k >= 1; k--){
				if(res(i, j, k)){
					marcar(i, j, k);
					vetor.PB(Aux(i,j, k));
				}
			}
		}
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(matriz[i][j] == '*'){
				cout << "-1" << endl;
				return 0;	
			}
		}
	}

	cout << vetor.size() << endl;
	
	for(auto a: vetor){
		cout << a.x << " " << a.y << " " << a.t << endl;
	}
	
	return 0;
}
