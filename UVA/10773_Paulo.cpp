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
	int t;
	cin >> t;

	
	for(int i=1; i<=t; i++){
		
		int d, v, u;
		cin >> d >> v >> u;
		
		if(v and u and (u > v)){			
			cout.precision(3);
			cout << fixed;
			
			cout << "Case " << i << ": " << abs(d/double(u) - d/sqrt(u*u - v*v)) << endl;
		}else{
			cout << "Case " << i << ": " << "can't determine" << endl;
		}
		
	}
		
	return 0;
}
