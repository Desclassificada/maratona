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
	
	cout << "PERFECTION OUTPUT" << endl;
	
	int n;
	cin >> n;
	
	while(n){
		
		int sum=1;
		int raiz = sqrt(n);
		
		if( (raiz*raiz) == n ){
			sum += raiz;
					
			for(int i=2; i < raiz; i++){
				if( (n%i) == 0){
					sum += i + (n/i);
				}
			}
		}else{
			for(int i=2; i <= raiz; i++){
				if( (n%i) == 0){
					sum += i + (n/i);
				}
			}			
		}

		int aux = n;
		
		while(aux < 9999){
			cout << ' ';
			aux  *= 10;
		}
		if(n == 1){
			cout << n << "  DEFICIENT" << endl;
		}else if(sum == n){
			cout << n << "  PERFECT" << endl;
		}else if(sum < n){
			cout << n << "  DEFICIENT" << endl;
		}else{			
			cout << n << "  ABUNDANT" << endl;
		}
		
		cin >> n;		
	}

	cout << "END OF OUTPUT" << endl;
		
	return 0;
}
