#include <bits/stdc++.h>

using namespace std;
string a, b;

int res(int i, int j){
	if(i > j)
		return 0;
		
	if(i == j){
		if(a[i] == b[i])
			return 0;
		else
			return 1;
	}
	
	set<int> teste;
	teste.insert(a[i]);
	teste.insert(b[i]);
	teste.insert(a[j]);
	teste.insert(b[j]);
	
	if(a[i] == b[i] and a[j] == b[j])
		return res(i+1, j-1);
		
	if(a[i] == a[j] and b[i] == b[j])
		return res(i+1, j-1);
		
	if(a[i] == b[j] and b[i] == a[j])
		return res(i+1, j-1);
	
	if(a[i] == a[j] and b[i] != b[j] and a[i]!=b[i] and a[i]!=b[j])
		return 2 + res(i+1, j-1);
	
	if(teste.size() == 4)
		return 2 + res(i+1, j-1);
		
	return 1 + res(i+1, j-1);
}

int main(){
	int n;
	cin >> n;
	cin >> a;
	cin >> b;

	cout << res(0, n-1) << endl;
	
    return 0;
}

