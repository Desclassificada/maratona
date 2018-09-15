#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define MOD 1000000007ll
#define ORDEM 3

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

long long res(long n){
	if(n <= 0)
		return 0LL;
	if(n == 1)
		return 1LL;
	
	base[0][0] = 1LL;
	base[0][1] = 1LL;
	base[0][2] = 0LL;
		
	base[1][0] = 1LL;
	base[1][1] = 0LL;
	base[1][2] = 0LL;
	
	base[2][0] = 1LL;
	base[2][1] = 1LL;
	base[2][2] = 1LL;
	
	for(int i=0; i < ORDEM; i++){
		for(int j=0; j < ORDEM; j++){
			mat[i][j] = base[i][j];
		}
	}
			
	expo(mat, n-1);
	
	return ( mat[2][0] + mat[2][2])%MOD;
}

int main(){		
	cin.tie(0);
	cin.sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){	
		long int l, r;
		cin >> l >> r;
		ll ans = res(r) - res(l-1);
		if(ans < 0)
			ans += MOD;
			
		printf("%lld\n", ans);
	}
	
	return 0;
}
