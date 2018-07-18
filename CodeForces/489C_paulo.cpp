#include <iostream>

using namespace std;

int main(){
	
	int n, s;
	
	cin >> n >> s;
	if((s > 0 or n==1) and n*9 >= s){
		int falta = s;
		
		string maior(n, '0');

		if(falta > 0)
			maior[0] = '1', falta--;
		
		if(falta >= 8){
			maior[0] = '9';
			falta -= 8;
		}else{
			maior[0] += falta;
			falta = 0;
		}
				
		for(int i=1; falta > 0; i++){
			if(falta >= 9){
				maior[i] = '9';
				falta -= 9;
			}else{
				maior[i] += falta;
				falta = 0;
			}
		}
		
		falta = s;
		string menor(n, '0');
		
		if(falta > 0)
			menor[0] = '1', falta--;
		
		for(int i=n-1; falta > 0; i--){
			if(falta >= 9){
				menor[i] = '9';
				falta -= 9;
			}else{
				menor[i] += falta;
				falta = 0;
			}
		}
		
		cout << menor << " " << maior << endl;
		
	}else{
		cout << -1 << " " << -1 << endl;
	}
	return 0;
}
