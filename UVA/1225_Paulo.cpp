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
	
	int n;
	cin >> n;
	
	while(n--){
		int a;
		int cont = 0;
		cin >> a;
		string aux;
		
		for(int i=1; i<=a; i++)
			aux = aux + to_string(i);
		
		for(char i = '0'; i<'9'; i++){
			cont = 0;
			for(char c: aux)
				if(c == i)
					cont++;
			
			cout << cont << ' ';
		}
		
		cont = 0;
		for(char c: aux)
			if(c == '9')
				cont++;
			
		cout << cont << '\n';
	}
		
	return 0;
}
