#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back

using namespace std;

long int vetor[4001000];
vector< pair<long, long> > res;

int main(){
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> vetor[i];
	}
	
	sort(vetor, vetor+n);
	
	for(int i=1; i<n; i++){
		if(vetor[i] - vetor[i-1] > 0)
			res.PB(MP(vetor[i], vetor[i-1]));
		
		vetor[i] -= vetor[i-1];		
		if(vetor[i] == 0)
			i++;
	}
	
	if(vetor[n-1]%2 == 0){
		if(vetor[n-1] > 0)
			res.PB(MP(vetor[n-1], vetor[n-1]/2));
		
		cout << res.size() << endl;
		
		for(auto i : res){
			cout << i.first << " " << i.second << endl;
		}
	}else{
		cout << -1 << endl;
	}
	
	
	return 0;
}
