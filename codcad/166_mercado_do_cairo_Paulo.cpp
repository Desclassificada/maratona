#include <bits/stdc++.h>
#define MAXN 1002

using namespace std;

int t[MAXN][MAXN];

int maximo(int x, int y){
	int m = 0;
	
	for(int a=x; a>0; a-= a&-a){
		for(int b=y; b>0; b-=b&-b){
			m = max(t[a][b], m);
		}
	}
	return m;
}

void atualizar(int x, int y, int v){
	for(int a=x; a<MAXN; a+= a&-a){
		for(int b=y; b<MAXN; b+=b&-b){
			t[a][b] = max(v, t[a][b]) ;
		}
	}
	
}

int main(){	
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int test, n;
	cin >> test;
	
	while(test--){
		
		int maxi = 0;
		cin >> n;
		
		for(int i=0; i<n; i++){
			int a, b;
			cin >> a >> b;

			int m = maximo(a, b) + 1;			
			atualizar(a, b, m);
			
			maxi = max(maxi, m);
			
		}
		
		cout << maxi << endl;
		
		memset(t, 0, sizeof(t));
	}
	
	return 0;
}
