#include <bits/stdc++.h>
#define INF 3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN
#define MAXM
#define endl '\n'

typedef long long int ll;

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n;
	int x;
	
	cin >> n >> x;
	
	int cont = 10;
		
	for(ll i=10000000000; i>=10ll; i/=10ll){
		long int resto = n%i;
		string aux = to_string(i-resto);
		
		int soma = 0;
		for(char c: aux){
			soma += (c - '0');
		}
		
		if(soma <= x){
			if(cont == 10)
				cont += (x-soma)/9;
				
			cout << cont << endl;
			return 0;
		}
		
		cont--;
	}
	
	cout << '0' << endl;
	
	return 0;
}
