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

long vet[80];

int main() {
	int n;
	
	vet[1] = 1;
	vet[2] = 2;
	vet[3] = 2;
	
	for(int i=4; i<=76; i++)
		vet[i] = vet[i-2] + vet[i-3];	
	
	while(cin >> n)
		cout << vet[n] << endl;	
	
	return 0;
}
