#include <bits/stdc++.h>
#define MAXN 10000

using namespace std;

int toLeaf[MAXN];
int maxLength[MAXN];

vector<int> adj[MAXN];

int diameter(int v, int e){
	int m1=0, m2=0;
	
	for(int u: adj[v]){
		if(u == e)
			continue;
			
		diameter(u, v);
		
		toLeaf[v] = max(toLeaf[v], toLeaf[u]+1);
		
		if(toLeaf[u] > m2){
			m2 = toLeaf[u];
			
			if(m2 > m1)
				swap(m1, m2);
		}
	}
		
	if(m1 and m2){
		maxLength[v] = m1 + m2 + 2;
	}else{
		maxLength[v] = max(toLeaf[v], maxLength[adj[v].back()]);
	}
	
	return maxLength[v];
}

//diameter(1, 0);

int main(){
	long int n;
	
	//test for code
	cin >> n;
	
	for(int i=1; i<n; i++){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	cout << diameter(1, 0) << endl;
}

