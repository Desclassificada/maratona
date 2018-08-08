#include <bits/stdc++.h>

using namespace std;

int disp[320];
int tam[320];
 
int main(){
	int n, w;
	cin >> n >> w;
	
	for(int i=1; i<=n; i++){
		cin >> disp[i];
		cin >> tam[i];
	}
	int soma = 0;
	
	for(int i=1; i<=n; i++){
		soma = 0;
		
		for(int j=i; j <=n; j++){
			if(disp[j] == 0){
				i=j;
				break;
			}
			
			soma += tam[j];
			
			if(soma >= w){
				cout << i <<endl;
				return 0;
			}
		}
	}
	
	cout << -1 << endl;

	return 0;
}
