#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define MOD 10000l

#define MP make_pair
#define PB push_back
#define F first
#define S second

#define MAXN 100010
#define MAXM 
#define endl '\n'

typedef long long int ll;
typedef pair<long int, long int> pii;

struct M{
	#define MAX 2
	long mat[MAX][MAX];
	
	M mul(M m){
		M res;
		for(int i=0; i<MAX; i++){
			for(int j=0; j<MAX; j++){
				res.mat[i][j] = 0;				
				for(int k=0; k<MAX; k++)
					res.mat[i][j] = (res.mat[i][j] + (mat[i][k] * m.mat[k][j])%MOD )%MOD;
			}
		}
		return res;
	}

	M add(M m){
		M res;
		
		for(int i=0; i<MAX; i++){
			for(int j=0; j<MAX; j++){
				res.mat[i][j] = mat[i][j] + m.mat[i][j];				
			}
		}
		
		return res;
	}
	
};

M expM(M m, long int n){
	if(n == 1)
		return m;
	
	M r = expM(m, n/2);
	r = r.mul(r);
	
	if( (n%2) == 1 ){
		r = r.mul(m);
	}
	
	return r;
}

int main(){		
//	cin.tie(0);
//	cin.sync_with_stdio(0);

	long t;
	
	cin >> t;
	
	while(t--){	
		long a, b, n, m;
		cin >> a >> b >> n >> m;
		
		M base;
		base.mat[0][0] = 1; 
		base.mat[0][1] = 1;
		base.mat[1][0] = 1; 
		base.mat[1][1] = 0; 
		
				
		if(n == 0)
			cout << a%MOD << endl;
		else if(n == 1)
			cout << b%MOD << endl;			
		else{			
			M res = expM(base, n-1);
			long int mod = pow(10, m);
			
			cout << ( (res.mat[0][0]*(b))%mod + (res.mat[0][1]*a)%mod)%mod << endl;
		}
	}
	
	return 0;
}
