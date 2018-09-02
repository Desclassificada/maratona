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
ll vet[500100];

int main(){		
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	long int n;
	ll v;
	
	cin >> n >> v;
	
	for(int i=0; i<n; i++){
		cin >> vet[i];
	}
		
	sort(vet, vet + n);
	if(vet[n/2] == 0){
		cout << 0 << endl;
	}else if(vet[n/2] < v){
		ll res = 0;
		for(int i=n/2; (i < n) and (vet[i] < v); i++){
			res += v - vet[i];
		}
		cout << res << endl;
	}else{
		ll res = 0;
		for(int i=n/2; (i >= 0) and (vet[i] > v); i--){
			res += vet[i] - v;
		}		
		cout << res << endl;
	}
	return 0;
}
