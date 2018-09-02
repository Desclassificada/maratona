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

int main(){		
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int a, b;
	int t = 1;

	cin >> a >> b;	
	
	while(a and b){
		int v = (a-1)/b;
		
		if(v <= 26)
			cout << "Case " << t << ": " << v << endl;
		else
			cout << "Case " << t << ": " << "impossible" << endl;
		
		t++;	
		cin >> a >> b;	
	}
		
	return 0;
}
