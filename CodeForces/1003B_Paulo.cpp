#include <bits/stdc++.h>

using namespace std;

int main(){

	int a, b, x;
	
	cin >> a >> b >> x;
	
	bool at = b > a;
	
	while(x >= 0){
		cout << at;
		
		if(at) b--;
		else a--;
		
		while(x == 1 && at == 1 && b > 0){
			cout << at;
			b--;
		}
		
		while(x == 1 && at == 0 && a > 0){
			cout << at;
			a--;
		}
		
		while(x == 0 && at == 1 && b > 0){
			cout << at;
			b--;
		}
		
		while(x == 0 && at == 0 && a > 0){
			cout << at;
			a--;
		}
		
		at = !at;
		x--;			
	}
	
	cout << endl;
	
	return 0;
}
