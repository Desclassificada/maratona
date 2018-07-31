#include <bits/stdc++.h>
#define INF 3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN
#define MAXM

typedef long long int ll;

using namespace std;

ll vetor[100010];

int main(){
	ll total = 0;
	ll n, m;
	long int cont = 0;
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		ll a, b;
		cin >> a >> b;
		vetor[i] = a - b;
		total += a;
	}
	
	sort(vetor, vetor+n);
	
	for(int i = n-1; i >=0 and total > m ; i--){
		total -= vetor[i];
		cont++;
	}
	
	if(total <= m)
		cout << cont << endl;
	else
		cout << -1 << endl;
	
	return 0;
}
