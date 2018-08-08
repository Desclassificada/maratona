#include <bits/stdc++.h>

using namespace std;

int main(){
	long int n;
	long int ant = 1000000010;
	
	string res = "YES";
	cin >> n;
	
	for(long int i=0; i<n; i++){
		long int a, b;
		
		cin >> a >> b;
				
		if(max(a, b) <= ant){
			ant = max(a, b);
		}else if(min(a, b) <= ant){
			ant = min(a, b);			
		}else{
			res = "NO";
			ant = min(a, b);
		}
				
	}
	

	cout << res << endl;

	return 0;
}
