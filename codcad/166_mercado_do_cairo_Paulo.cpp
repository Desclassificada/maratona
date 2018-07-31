#include <bits/stdc++.h>
#define MAXC 1010

using namespace std;

int tree[MAXC][MAXC];

int querie(int a, int b){
	
	return sum(a, b) - sum(a-1, b) - sum(a, b-1) + sum(a-1, b-1);
}

int sum(int a, int b){
	int s = 0;
	
	for(int x=a; x > 0; x -= x&-x){
		for(int y=b; y>0; y -= y&-y){
			s += tree[x][y];
		}
	}
	
	return s;
}

void update(int a, int b, int d){
	for(int x=a; x < MAXC; x += x&-x){
		for(int y=b; y < MAXC; y += y&-y){
			tree[x][y] += d;
		}
	}	
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t, n;
	cin >> t;
	
	while(t--){
		memset(tree, 0, sizeof(tree));
		
		int maximo = 0;
		cin >> n;
		
		for(int i=0; i<n; i++){
			int a, b;
			cin >> a >> b;
			
			int op1 = querie(a-1, b);
			int op2 = querie(a, b-1);
			int op3 = querie(a-1, b-1);
			
			int 
			
			maximo = max(maximo, querie(a, b));
			
		}
		
		cout << maximo << endl;
	}
	
	return 0;
}
