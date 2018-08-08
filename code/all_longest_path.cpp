#include <bits/stdc++.h>
#define MAXN 10000

using namespace std;
typedef pair<int, int> pii;

//maxLength1[i].first = distancia maxima
//maxLength1[i].second = por quem passa

pii maxLength1[MAXN];
pii maxLength2[MAXN];

vector<int> adj[MAXN];

void dfs(int v, int e){
	
	for(int u: adj[v]){
		if(u == e)
			continue;
			
		dfs(u, v);
				
		if( (maxLength1[u].first+1) > maxLength2[v].first){
			maxLength2[v].first = maxLength1[u].first+1;
			maxLength2[v].second = u;
			
			if(maxLength2[v].first > maxLength1[v].first)
				swap(maxLength1[v], maxLength2[v]);
		}
	}
}

void dfs2(int v, int e){
	
	if(maxLength1[e].second != v){
		if( (maxLength1[e].first + 1) > maxLength2[v].first){
			maxLength2[v].first = maxLength1[e].first + 1;
			maxLength2[v].second = e;
			
			if(maxLength2[v].first > maxLength1[v].first)
				swap(maxLength1[v], maxLength2[v]);
			
		}
	}else{
		if( (maxLength2[e].first + 1) > maxLength2[v].first){
			maxLength2[v].first = maxLength2[e].first + 1;
			maxLength2[v].second = e;
			
			if(maxLength2[v].first > maxLength1[v].first)
				swap(maxLength1[v], maxLength2[v]);
			
		}
	}
	
	for(int u: adj[v]){
		if(u == e)
			continue;
						
		dfs2(u, v);				
	}
}

//diameter(1, 0);

int main(){
	long int n;
	
	maxLength1[0] = {-1, 0};
	maxLength2[0] = {-1, 0};
	//test for code
	cin >> n;
	
	for(int i=1; i<n; i++){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dfs(1, 0);
	dfs2(1, 0);
	
	for(int i=1; i<=n; i++){
		cout << maxLength1[i].first << " " << maxLength1[i].second << endl;
	}	
}

