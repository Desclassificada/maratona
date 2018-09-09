#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii > vpi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)*(b))/__gcd((a), (b)))

set<long int> adj[110];
vector<pii> arestas;
bool marcado[60];

void dfs(int v){
	marcado[v] = true;
	
	for(auto u: adj[v])
		if(!marcado[u])
			dfs(u);	
}

int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	long int n, m;
	
	while(cin >> n >> m){
		
		arestas.clear();
		for(int i=0; i<90; i++){
			adj[i].clear();
		}
	
		for(int i=0; i<m; i++){
			int a, b;
			cin >> a >> b;
			
			adj[a].insert(b);
			adj[b].insert(a);
			arestas.PB({a, b});
		}
		
		int componetesAnt = 1;
		
		for(pii a : arestas){
			memset(marcado, 0, sizeof(marcado));
			
			int cont = 0;
			adj[a.F].erase(a.S);
			adj[a.S].erase(a.F);
			
			for(int i=1; i<=n; i++){
				if(!marcado[i]){
					dfs(i);
					cont++;
				}					
			}
			
			if(cont == componetesAnt){
				adj[a.F].insert(a.S);
				adj[a.S].insert(a.F);				
			}else{
				componetesAnt = cont;
			}
		}
			
		cout << componetesAnt-1 << endl;
		
	}
	
	return 0;
}
