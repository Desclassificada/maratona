#include <bits/stdc++.h>

using namespace std;

map<long int, long int> mapa;

int main(){
	long int n, p;
	
	cin >> n >> p;
	
	for(long int i=0; i < n; i++){
		long int x;
		cin >> x;
		
		mapa[x]++;
 	}
 	
	for(long int k=0; k < p; k++){
		long int moedas = 0;
		long int v;
		cin >> v;
		
		for(auto it = mapa.rbegin(); it != mapa.rend(); it++){
			
			if(v >= it->first){
				long int div = v/(it->first);
				v -= (it->first) * min(div, it->second);
				moedas += min(div, it->second);
			}
		}
		
		if(v == 0){
			cout << moedas << endl;
		}else{
			cout << "-1" << endl;
		}
	
	}
	
	return 0;
}
