#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<long int, null_type, less<long int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

/*
	o.find_by_order(index)
	o.order_of_key(value)	
	o.find(value)
*/

#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f

#define MP make_pair
#define PB push_back
#define MAXN 50010
#define MAXM 500010
#define endl '\n'

#define cind(a) scanf("%lf", &a)
#define cinc(a) scanf(" %c", &a)
#define cinll(a) scanf("%lld", &a)

#define cini(a) scanf("%ld", &a)
#define cin2i(a, b) scanf("%ld %ld", &a, &b)
#define cin3i(a, b, c) scanf("%ld %ld %ld", &a, &b, &c)
#define cin4i(a, b, c, d) scanf("%ld %ld %ld %ld", &a, &b, &c, &d)
#define cin5i(a, b, c, d, e) scanf("%ld %ld %ld %ld %ld", &a, &b, &c, &d, &e)

#define coutd(a) printf("%lf", a)
#define coutdl(a) printf("%lf\n", a)
#define coutc(a) printf("%c", a)
#define coutcl(a) printf("%c\n", a)
#define coutll(a) printf("%lld", a)
#define coutlll(a) printf("%lld\n", a)

#define couti(a) printf("%ld", a)
#define coutil(a) printf("%ld\n", a)
#define cout2i(a, b) printf("%ld %ld\n", a, b)
#define cout3i(a, b, c) printf("%ld %ld %ld\n", a, b, c)
#define cout4i(a, b, c, d) printf("%ld %ld %ld %ld\n", a, b, c, d)
#define cout5i(a, b, c, d, e) printf("%ld %ld %ld %ld %ld\n", a, b, c, d, e)

#define WHILE(n) for(int i=0; i<n; i++)
#define FOR(v, m) for(int v=0;v<m; v++)

#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)*(b))/__gcd((a), (b)))

typedef long long int ll;
typedef pair<long int, long int> pii;

long int grau[100010];
long int grau2[100010];
vector<long int> adj[100010];

int main(){	
	long int n, m;
	
	cin2i(n, m);
	
	FOR(i, m){
		long int a, r, b;		
		cin3i(a, r, b);
		if(r == 1){
			grau[b]++;
			grau2[b]++;
			adj[a].PB(b);
		}else{
			grau[a]++;
			grau2[a]++;
			adj[b].PB(a);			
		}		
	}
	queue<long int> fila;
	
	
	//comecando com a pares
	
	for(int i=2; i<=2*n; i+=2){
		if(grau[i] == 0)
			fila.push(i);
	}
	
	for(int i=1; i<=2*n; i+=2){
		if(grau[i] == 0)
			fila.push(i);
	}
	long int cont = 1;
	
	bool p = true;
	
	while(!fila.empty()){
		long int f = fila.front(); fila.pop();
		
		if((f%2)==p){
			p = !p;
			cont++;
		}
		
		for(long int u: adj[f]){
			grau[u]--;
			
			if(grau[u] == 0)
				fila.push(u);
		}
	}
	
	//começando com as impares
		
	for(int i=1; i<=2*n; i+=2){
		if(grau2[i] == 0)
			fila.push(i);
	}
	
	for(int i=2; i<=2*n; i+=2){
		if(grau2[i] == 0)
			fila.push(i);
	}
	
	long int cont2 = 1;
	
	p = false;
	
	while(!fila.empty()){
		long int f = fila.front(); fila.pop();
		
		if((f%2)==p){
			p = !p;
			cont2++;
		}
		
		for(long int u: adj[f]){
			grau2[u]--;
			
			if(grau2[u] == 0)
				fila.push(u);
		}
	}
	
	coutil(min(cont, cont2));
	
	return 0;
}
