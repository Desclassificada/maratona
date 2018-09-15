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

int ler(){
	string c;
	cin >> c;
	if(c == "A")
		return 1;
	if(c == "J")
		return 11;
	if(c == "Q")
		return 12;
	if(c == "K")
		return 13;
	
	return stoi(c);
}

int vet[70];
//int acu[70];

const int inf = 790;

unordered_map<int, unordered_map<int, int> > memo[60][11];//[800];
int n, k;

int pd(int i, int f, int s, int m){
	if( (i == n) and (f == 0) )
		return m;			
	if( (i == n) or (f == 0))
		return inf;
	
	if(memo[i][f][s][m] != 0)
		return memo[i][f][s][m];
	
	return memo[i][f][s][m] = min( pd(i+1, f-1, 0, max(s+vet[i], m)), pd(i+1, f, s+vet[i], m) );		
}

int main(){		
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	cin >> n >> k;
	
	for(int i=0; i<n; i++){
		vet[i] = ler();
/*		acu[i] += vet[i]; 
		acu[i+1] = acu[i];*/
	}
	
	int maximo = pd(0, k, 0, 0);
	int sum = 0;
	int cont = 0;
	int cartas = 0;
	
	for(int i=0; i<n; i++){
		if( sum+vet[i] <= maximo){
			sum += vet[i];
			cont++;
		}else{
			cartas = max(cartas, cont);
			sum=vet[i];
			cont=1;
		}
	}
	
	cartas = max(cartas, cont);
		
	cout << cartas << " " << maximo << endl; 
			
	return 0;
}
