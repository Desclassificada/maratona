#include <bits/stdc++.h>

using namespace std;

int main(){
	
	long int n, x;
	
	cin >> n;
	cin >> x;
	
	if(x%2 == 0){
		cout << x - 1;
	}else{
		cout << x;		
	}
	
	for(long int i=1; i<n; i++){
		cin >> x;
		
		if(x%2 == 0){
			cout << " " << x - 1;
		}else{
			cout << " " << x;		
		}
	
	}
		
	cout << endl;

    return 0;
}

