#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN 50010
#define MAXM 500010
#define endl '\n'
#define cin2i(a, b) scanf("%ld %ld", &a, &b)
#define cin5i(a, b, c, d, e) scanf("%ld %ld %ld %ld %ld", &a, &b, &c, &d, &e)

using namespace std;

typedef long long int ll;
typedef pair<long int, long int> pii;
typedef tuple<long int, long int, long int, long int> t4i;

priority_queue< pii, vector<pii>, greater<pii> > fila;

long int menor[MAXN];
vector<t4i> adj[MAXN];

void menorCaminho(){
	memset(menor, 0x3f, sizeof(menor));
	
	menor[1] = 0;		
	fila.push(pii(0, 1));
	
	while(!fila.empty()){
		int t = fila.top().first;
		int v = fila.top().second; 
		fila.pop();
		
		for(t4i aux: adj[v]){
			long int u = get<0>(aux);
			long int d = get<1>(aux);
			long int a = get<2>(aux);
			long int f = get<3>(aux);
			
			if( (t+d)%(a+f) < a){ //chegou e o sinal estava aberto
				if(t+d < menor[u]){
					menor[u] = t+d;
					fila.push(pii(t+d, u));
				}
			}else{ //sinal fechou
				if((t+d+(a+f - ((t+d)%(a+f)) )) < menor[u]){
					menor[u] = (t+d+(a+f - ((t+d)%(a+f)) ));
					fila.push(pii((t+d+(a+f - ((t+d)%(a+f)) )), u));
				}				
			}
		}
	}
}

int main(){
	
	long int n, m;
	cin2i(n, m);
	
	for(int i=0; i<m; i++){
		long int x, y, d, a, f;
		
		cin5i(x, y, d, a, f);
		
		adj[x].PB(t4i(y, d, a, f));
		
	}
	
	menorCaminho();
	
	cout << menor[n] << endl;
	
	return 0;
}
