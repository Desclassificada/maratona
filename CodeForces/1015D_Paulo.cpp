#include <bits/stdc++.h>
#define INF 3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN
#define MAXM

typedef long long int ll;

using namespace std;

int main(){
	
	ll n, m, s, resto;
	cin >> n >> m >> s;
	ll p = s/m;
	resto = s%m;
	
	ll f = p + 1ll;
	
	if((f + (resto > 0 )) > n or s < m){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
		ll atual = f+(resto > 0);
		ll muda = -1ll;
		cout << atual;
		
		if(resto > 0)
			resto--;
		
		for(ll i=1ll; i<m; i++){
			atual += muda*(p+(resto > 0));
			cout << " " << atual;
			muda *= -1ll;
			
			if(resto > 0)
				resto--;
		}
	}
		
	return 0;
}
