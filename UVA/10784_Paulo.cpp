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

int main() {
	long long int n;
	cin >> n;
	int t = 1;
	while(n > 0){		
		cout << "Case "<< t << ": " << (long long)(ceill((3+sqrtl(9+8*n))/2.0)) << endl;	
		cin >> n;
		t++;
	}
	
	return 0;
}
