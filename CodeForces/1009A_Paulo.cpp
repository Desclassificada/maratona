#include <bits/stdc++.h>

using namespace std;

int main(){	
	queue<int> fn;
	queue<int> fc;
	int n, c;
	
	cin >> n >> c;
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		fn.push(x);
	}	
	
	for(int i=0; i<c; i++){
		int x;
		cin >> x;
		fc.push(x);
	}	
	int cont = 0;
	while(!fc.empty() and !fn.empty()){
		if(fc.front() >= fn.front()){
			fc.pop();
			fn.pop();
			cont++;
		}else{
			fn.pop();
		}
	}
	
	
	cout << cont << endl;
	
	return 0;
}
