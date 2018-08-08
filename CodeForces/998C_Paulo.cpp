#include <bits/stdc++.h>

using namespace std;

char vetor[300100];

int cont = 0;	
long long int x, y;
int n;

long long int res(int p){
	if(p == 0)
		return 0;
	
	return (p-1) * min(x, y) + y;
}

int main(){
	cin >> n >> x >> y;

	cin >> vetor;
	bool at = 1;
	
	for(int i=0; i<n; i++){
		if(at){
			if(vetor[i] == '0'){
				cont++;
				at = 0;
			}
		}else{
			if(vetor[i] == '1'){
				at = 1;
			}
		}		
	}
	
	
	cout << res(cont) << endl;
	
	return 0;
}
