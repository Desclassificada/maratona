#include <bits/stdc++.h>

using namespace std;

pair<int, int> vetor[2010];
int pos[2010];

int comp(pair<int, int> a, pair<int, int> b){
	if(a.first == b.first)
		return a.second < b.second;
	
	return a.first > b.first;
}

int main(){
	long int soma = 0;
	
	int n, k;
	cin >> n >> k;
	
	for(int i=0; i<n; i++){
		cin >> vetor[i].first;
		vetor[i].second = i;
	}
	
	sort(vetor, vetor + n, comp);

	for(int i=0; i<k; i++){
		soma += vetor[i].first;
		pos[i] = vetor[i].second;
	}
	
	sort(pos, pos + k);
	cout << soma << endl;
	
	if(k == 1)
		cout << n << endl;
	else{
		pos[k] = n;
		cout << pos[1];
		
		for(int i=2; i<=k; i++){
			cout << " " << pos[i] - pos[i-1];
		}
	}
	
	cout << endl;
	
    return 0;
}

