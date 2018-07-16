#include <bits/stdc++.h>

using namespace std;

int mmc(long int a, long int b){
	if(b == 0)
		return a;
		
	return mmc(b, a%b);
}

vector< pair<int, int> > res;

int main(){	
		
	int cont = 0;
	int n, m;
	cin >> n >> m;
	
	for(int i=1; i <=n && cont < m; i++){
		for(int j=i+1; j <=n && cont < m; j++){
			if(mmc(i, j) == 1){
				res.push_back(make_pair(i, j));
				cont++;
			}
		}
	}
	
	if(cont == m and m >= (n-1)){
		cout << "Possible" << endl;
		
		for(auto a: res){
			cout << a.first << " " << a.second << endl;
		}
	}else{
		cout << "Impossible" << endl;		
	}
		
	return 0;
}
