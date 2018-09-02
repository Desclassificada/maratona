#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define MOD 1000000ll
#define ORDEM 2

#define MP make_pair
#define PB push_back
#define F first
#define S second

#define MAXN 100010
#define MAXM 
#define endl '\n'

typedef long long int ll;
typedef pair<long int, long int> pii;

long long base[ORDEM][ORDEM];
long long mat[ORDEM][ORDEM];
long long n, k, l;

void mult(long long matA[ORDEM][ORDEM], long long matB[ORDEM][ORDEM]){
	long long aux[ORDEM][ORDEM];
	
	for(int i=0; i < ORDEM; i++){
		for(int j=0; j < ORDEM; j++){
			long long soma = 0LL;
			
			for(int k=0; k < ORDEM; k++){
				soma = (soma + (matA[i][k] * matB[k][j])%MOD)%MOD;
			}
			
			aux[i][j] = soma;
		}
	}
	
	for(int i=0; i < ORDEM; i++){
		for(int j=0; j < ORDEM; j++){
			matA[i][j] = aux[i][j];
		}
	}
	
}

void expo(long long matA[ORDEM][ORDEM], long long n){
	if(n <= 1LL)
		return;
		
	expo(matA, n/2);
	mult(matA, matA);
	
	if(n % 2LL == 1LL)
		mult(matA, base);
		
}

long long res(long long n){
	if(n == 0LL)
		return 1LL;
	if(n == 5LL)
		return k;
	
	base[0][0] = k;
	base[0][1] = l;
	base[1][0] = 1LL;
	base[1][1] = 0LL;
	
	for(int i=0; i < ORDEM; i++){
		for(int j=0; j < ORDEM; j++){
			mat[i][j] = base[i][j];
		}
	}
			
	expo(mat, (n/5ll) - 1ll);
	
	return (( mat[0][0]*k)%MOD + mat[0][1])%MOD;
}

int main(){		
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	while(cin >> n >> k >> l){	
		k = k%MOD;
		l = l%MOD;
		printf("%06lld\n", res(n));
	}
	return 0;
}
