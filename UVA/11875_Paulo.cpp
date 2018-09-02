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

int vet[110];

int main(){		
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int t;
	
	cin >> t;
	
	for(int i=1; i<=t; i++){
		int n;
		cin >> n;
		
		for(int i=0; i<n; i++)
			cin >> vet[i];
			
		sort(vet, vet + n);
		
		cout << "Case " << i << ": " << vet[n/2] << endl;
	}
		
	return 0;
}
