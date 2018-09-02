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

set<long> arestas[200010];
vector<long> adj[200010];
long grau[200010];
bool vai[200010];

vector<pii> a;
vector<long> r;

int main(){		
	cin.tie(0);
	cin.sync_with_stdio(0);
	long n, m, k;
	long fest = 0;
	
	cin >> n >> m >> k;
		
	for(int i=0; i<m; i++){
		long x, y;
		cin >> x >> y;
		
		a.PB({x, y});
		
		adj[x].PB(y);
		adj[y].PB(x);
		arestas[x].insert(y);
		arestas[y].insert(x);
		
		grau[x]++;
		grau[y]++;		
	}
	
	queue<long> fila;
	
	for(int i=1; i<=n; i++){
		if(grau[i] < k){
			fila.push(i);
			vai[i] = false;
		}else{
			vai[i] = true;
			fest++;
		}
	}
	
	while(!fila.empty()){
		long f = fila.front(); fila.pop();
		
		for(long v: adj[f]){
		
			if(arestas[f].find(v) != arestas[f].end()){			
				grau[f]--;
				grau[v]--;
				arestas[v].erase(f);
				arestas[f].erase(v);
				
				if(!vai[v])
					continue;
				
				if( grau[v] < k){
					fila.push(v);
					
					vai[v] = false;
					fest--;
				}
			}
		}			
	}
	
	for(int i=m-1; i>=0; i--){
		r.PB(fest);
		
		long x = a[i].first;
		long y = a[i].second;

		if(arestas[x].find(y) != arestas[x].end()){
			grau[x]--;
			grau[y]--;
			arestas[y].erase(x);
			arestas[x].erase(y);			

			if(vai[y]){				
				if( grau[y] < k){
					fila.push(y);
					vai[y] = false;
					fest--;
				}				
			}

			if(vai[x]){
				if(grau[x] < k){
					fila.push(x);
					vai[x] = false;
					fest--;	
				}
			}			
		}
		
		while(!fila.empty()){
			long f = fila.front(); fila.pop();
			
			for(long v: adj[f]){
			
				if(arestas[f].find(v) != arestas[f].end()){			
					grau[f]--;
					grau[v]--;
					arestas[v].erase(f);
					arestas[f].erase(v);
					
					if(!vai[v])
						continue;
					
					if( grau[v] < k){
						fila.push(v);
						
						vai[v] = false;
						fest--;
					}
				}
			}			
		}
						
	}
	
	reverse(r.begin(), r.end());
	
	for(long x : r)
		cout << x << endl;
	
	return 0;
}
