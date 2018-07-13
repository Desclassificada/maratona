#include <bits/stdc++.h>

using namespace std;

bool isVogal(char c){
	if( (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') )
		return true;
		
	return false;
}

int main(){	
	string texto;	
	cin >> texto;
	
	
	bool vez = isVogal(texto[0]);
	char ant = texto[0];
	string res = "YES";
	
	for(int i=1; i< (int)texto.size(); i++){
		if((!vez) and (!isVogal(texto[i])) and (ant != 'n')){
			res = "NO";
			break;
		}
		
		vez = isVogal(texto[i]);
		ant = texto[i];
	}
	
	if((!vez) && ant != 'n')
		res = "NO";
		
	cout << res << endl;
		
	return 0;
}
