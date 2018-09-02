#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define MOD 1000000007ll

#define MP make_pair
#define PB push_back
#define F first
#define S second

#define MAXN 100010
#define MAXM 
#define endl '\n'

typedef long long int ll;
typedef pair<long int, long int> pii;
int n, a, b, c;

int dist[110];
int pai[110];
vector<int> adj[110];

void dfs(int v, int e){
	for(int u: adj[v]){
		if(u != e){
			dist[u] = dist[v] + 1;
			pai[u] = v;
			
			if(u != b and u != c)
				dfs(u, v);
				
		}
	}
}

double probabilidade(){
	int db = 0;
	int dc = 0;
	
	while(dist[c] > dist[b]){
		c = pai[c];
		dc++;
	}

	while(dist[b] > dist[c]){
		b = pai[b];
		db++;
	}
	
	while(b != c){
		c = pai[c];
		b = pai[b];
		dc++;
		db++;		
	}
	
	return dc/(double)(db+dc);
	
}


int main(){		
	while(cin >> n >> a >> b >> c){
		memset(dist, 0, sizeof(dist));
		
		for(int i=0; i<=n; i++)
			adj[i].clear();
		
		for(int i=1; i<n; i++){
			int d, e;
			cin >> d >> e;
			
			adj[d].PB(e);
			adj[e].PB(d);			
		}
		
		dfs(a, 0);
		cout.precision(6);
		cout << fixed;
		
		if(dist[b] == 0)
			cout << 0.0 << endl;
		else if(dist[c] == 0)
			cout << 1.0 << endl;
		else
			cout << probabilidade() << endl;
		
	}
	
	return 0;
}
