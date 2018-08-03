#include <bits/stdc++.h>
#define INF 3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN
#define MAXM
#define endl '\n'

typedef long long int ll;

using namespace std;

int vetor[110];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q, x;
	cin >> n >> q >> x;
	
	vetor[x] = 1;
	
	for(int i=0; i<q; i++){
		int a, b;
		cin >> a >> b;
		
		swap(vetor[a], vetor[b]);
	}
	
	for(int i=1; i<=n; i++){
		if(vetor[i]){
			cout << i << endl;
			return 0;
		}	
	}
	
	return 0;
}
