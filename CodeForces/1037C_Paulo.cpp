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
	long int n;
	string a, b;
	
	cin >> n;
	cin >> a >> b;
	if(n == 1){
		if(a != b){
			cout << 1 << endl;
		}else{
			cout << 0 << endl;			
		}
	}else{
		long int cont = 0;
		
		for(int i=0; i<n-1; i++){
			if(a[i] == b[i])
				continue;
			if( (a[i] == b[i+1]) and (a[i+1] == b[i])){
				swap(a[i], a[i+1]);
				cont++;
				continue;
			}
			
			cont++;
		}
		
		if(a[n-1] != b[n-1])
			cont++;
			
		cout << cont << endl;
		
	}
		
	return 0;
}
