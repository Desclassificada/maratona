#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii > vpi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)*(b))/__gcd((a), (b)))

ll f[1000010];
ll sum[1000010];

int main() {
	
	for(int i=4; i<=1000000; i++){
		f[i] = f[i-2] + i-3LL;
		sum[i] = sum[i-1] + f[i]; 
	}
	
	int n;
	cin >> n;
	
	while(n >= 3){		
		cout << sum[n] << endl;	
		cin >> n;
	}
	
	return 0;
}
