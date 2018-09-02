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

long nivel[200010];
bool vis[200010];
long vet[200010];

set<long> adj[200010];

int main(){		
	cin.tie(0);
	cin.sync_with_stdio(0);
	memset(nivel, -1, sizeof(nivel));
	
	long int n;
	
	cin >> n;
	
	for(int i=1;i<n; i++){
		long x, y;
		cin >> x >> y;
		
		adj[x].insert(y);
		adj[y].insert(x);
	}
	for(int i = 1; i<=n; i++){
		cin >> vet[i];			
	}
	
	queue<long int> fila;
	vis[1] = true;
	nivel[1] = 0;
	fila.push(1);
	
	long p = 2;
	if(vet[1] == 1){	
		while(!fila.empty()){
			long v = fila.front(); fila.pop();
			
			while( adj[v].find(vet[p]) != adj[v].end() ){
				fila.push(vet[p]);
				
				adj[v].erase(vet[p]);
				adj[vet[p]].erase(v);
				p++;
			}
		}
	}
	if(p <= n){
		cout << "No" << endl;
	}else{
		cout << "Yes" << endl;		
	}
	
	return 0;
}
