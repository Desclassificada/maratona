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

unordered_map<long, long> mapa;
long int vet[100010];

pair<pii, long> query[100010];
long result[100010];
long n, q, id = 1, raiz;

long cont[100010];
long freq[100010];

bool comp(pair<pii, long> a, pair<pii, long> b){
	if( (a.F.F/raiz) == (b.F.F/raiz))
		return a.F.S < b.F.S;

	return a.F.F < b.F.F;
}

int main() {
	scanf("%ld %ld", &n, &q);
	raiz = sqrt(n); 
	
	for(int i=1;i <= n; i++){
		long x;
		scanf("%ld", &x);
		
		if(mapa.count(x)){
			vet[i] = mapa[x];
		}else{
			vet[i] = mapa[x] = id;
			id++;		
		}
	}
	
	mapa.clear();

	for(int i=0;i < q; i++){
		long l, r;
		scanf("%ld %ld", &l, &r);
		
		query[i] = make_pair(pii(l, r), i);
	}
	
	sort(query, query+q, comp);
	
	long l=0, r=0, f = 1;
		
	for(int i=0; i<q; i++){
		long a = query[i].F.F;
		long b = query[i].F.S + 1;
		long res = query[i].S;
		
		while(r < b){
			cont[vet[r]]++;
			freq[cont[vet[r]]]++;
			
			f = max(f, cont[vet[r]]);
			
			r++;
		}
		
		while(r > b){
			r--;
			if( (cont[vet[r]] < f) or (freq[cont[vet[r]]] > 1) ){				
				freq[cont[vet[r]]]--;
				cont[vet[r]]--;
			}else{
				freq[cont[vet[r]]]--;
				cont[vet[r]]--;
				
				f--;
			}			
		}

		while(l < a){
			if( (cont[vet[l]] < f) or (freq[cont[vet[l]]] > 1) ){				
				freq[cont[vet[l]]]--;
				cont[vet[l]]--;
			}else{
				freq[cont[vet[l]]]--;
				cont[vet[l]]--;
				
				f--;
			}			
			
			l++;			
		}
		
		while(l > a){			
			l--;	
					
			cont[vet[l]]++;
			freq[cont[vet[l]]]++;
						
			f = max(f, cont[vet[l]]);
						
		}
		
		result[res] = f;		
	}

	for(int i=0;i < q; i++){
		printf("%ld\n", result[i]);
	}		
	return 0;
}
