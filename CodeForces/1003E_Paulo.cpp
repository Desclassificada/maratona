#include <bits/stdc++.h>

using namespace std;

vector< pair<int, int> > vetor;
long int n, d, k;
long int vet;

int bfs(int v, int a, int b){
	int dis = 0;
	if(a == d)
		return 0;
	
	while(b < k and dis < d){
		if(vet == n)
			return 0;
			
		vet++;
		vetor.push_back(make_pair(v, vet));

		int x = bfs(vet, max(a+1, dis+1), 1) + 1;
		
		dis = max(x, dis);
		
		b++;
	}
	
	return dis;
}

int main(){
	
	cin >> n >> d >> k;
	
	vet = 1;
	
	bfs(1, 0, 0);
	
	if( (n <= d) or (int(vetor.size()) < (n-1))){
		cout << "NO" << endl;				
	}else{	
		cout << "YES" << endl;
		
		for(int i=0; i < n-1; i++){
			pair<int, int> p = vetor[i];
			cout << p.first << " " << p.second << endl;
		}
		
	}
	
	return 0;
}
