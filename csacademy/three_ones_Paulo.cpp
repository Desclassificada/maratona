#include <bits/stdc++.h>

using namespace std;

int soma[200010];
long int vetor[200010];

int main(){
	int n;
	string s;
	int res = 0;
	
	cin >> n;
	cin >> s;
	
	int soma = 0;
	int j = 0;
	for(int i=0;i <n; i++){
		for(; j<n; j++){
			if(s[j] == '1'){
				soma++;
			}
			
			if(soma == 3){
				res = max(res, j-i+1);
				while( i <n and s[i]!= '1') i++;
				while( i <n and s[i]== '1'){
					soma--;
					i++;
				}				
				i--;
				j++;
				break;
			}
		}
	
	}
	
	cout << res << endl;
	
	return 0;
}
