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

char mat[60][60];
int n, m;
ll memo[2600][2600];

ll comb(int n, int k){
	if(n == k)
		return 1LL;
	if(k == 0)
		return 1LL;
		
	if(memo[n][k] != -1LL)
		return memo[n][k];
		
	return memo[n][k] = ( comb(n-1, k) + comb(n-1, k-1) )%MOD;
}

int main(){	
	memset(memo, -1, sizeof(memo));
		
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> mat[i][j];
		}
	}
	
	int a, b, c, d;
	
	while(cin >> a >> b >> c >> d){
		int x=0, y=0;
		for(int i=a; i<=c; i++){
			for(int j=b; j<=d; j++){
				if(mat[i][j] == '#')
					x++;
				else
					y++;
			}
		}
		
		cout << comb(x+y, x) - 1LL << endl;
		
	}
	
	return 0;
}
