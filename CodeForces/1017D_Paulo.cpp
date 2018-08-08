#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<long int, null_type, less<long int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

/*
	o.find_by_order(index)
	o.order_of_key(value)	
	o.find(value)
*/

#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f

#define MP make_pair
#define PB push_back
#define F first
#define S second

#define MAXN 1000100
#define MAXM 
#define endl '\n'

#define cinc(a) scanf(" %c", &a)
#define cins(a) scanf(" %s", a)
#define cinll(a) scanf("%lld", &a)

#define cini(a) scanf("%ld", &a)
#define cin2i(a, b) scanf("%ld %ld", &a, &b)
#define cin3i(a, b, c) scanf("%ld %ld %ld", &a, &b, &c)
#define cin4i(a, b, c, d) scanf("%ld %ld %ld %ld", &a, &b, &c, &d)
#define cin5i(a, b, c, d, e) scanf("%ld %ld %ld %ld %ld", &a, &b, &c, &d, &e)

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

#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)*(b))/__gcd((a), (b)))

typedef long long int ll;
typedef pair<long int, long int> pii;

long int soma[4100][1400];
long int peso[14];
pii vet[500100];
long int size=0;
char aux[12];

map<int, long int> mapa;

int main(){	
	long n, q, m;
	cin3i(n, m, q);
	
	for(int i=0; i<n; i++)
		cini(peso[i]);
	
	for(int i=0; i<m; i++){		
		cins(aux);
		int v=0;
		for(int j=0; j<n; j++){
			if(aux[j] == '1')
				v += (1<<(n-1-j));
		}		
		
		mapa[v]++;
	}
	
	for(auto it : mapa){		
		vet[size++] = it;
	}
	
	for(int s=0; s < 1<<n; s++){
		for(int i=0; i<size; i++){		
			int v = vet[i].F;
			int f = vet[i].S;
			
			int a = (~(v^s));
			
			int sum = 0;
			
			for(int j=0; j<n; j++){
				if(a & (1<<(n-1-j))){
					sum += peso[j];	
				}
			}		
			
			soma[s][sum]+= f;
		}
		
		for(int i=1; i< 1400; i++){
			soma[s][i] += soma[s][i-1];
		}
	}
	
	for(int i=0; i<q; i++){
		long int a=0, k;
		cins(aux);
		cini(k);
		
		for(int j=0; j<n; j++){
			if(aux[j] == '1')
				a += (1<<(n-1-j));
		}		
		
		coutil(soma[a][k]);
	}
	
	return 0;
}
