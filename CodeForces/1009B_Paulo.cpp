#include <bits/stdc++.h>

using namespace std;
	
string texto;
int onde[100100];
int quanto[100100];

int main(){	
	int qtd2 = 0;
	
	cin >> texto;
	
	for(int i = texto.size()-1; i>=0; i--){
		quanto[i] += quanto[i+1];
		
		if(texto[i] == '1'){
			quanto[i]++;
		}else if(texto[i] == '2'){
			onde[qtd2] = i;
			qtd2++;
		}
	}
	
	for(int i=0; i< (int)texto.size(); i++){
		texto[i] = '0';
	}
	
	for(int i=0; i< qtd2; i++){
		texto[onde[i]+quanto[onde[i]]] = '2';
	}
	
	int pos = texto.size() -1;
	
	
	if(qtd2 >0)
		pos = onde[qtd2-1]+quanto[onde[qtd2-1]];

		
	int qtd1 = quanto[0];
	
	while(qtd1 > 0){
		if(texto[pos] == '0'){
			texto[pos] = '1';
			qtd1--;			
		}		
		pos--;
	}
		
	cout << texto << endl;
		
	return 0;
}
