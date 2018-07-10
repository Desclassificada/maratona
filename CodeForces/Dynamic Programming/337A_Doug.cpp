#include <bits/stdc++.h>

using namespace std;
#define INF 1073741823

int main() {
	int n,m;
	cin >> n >> m;
	vector<int>vetor(m);
	for(int i = 0; i < m;i++){
		cin >> vetor[i];
	}
	sort(vetor.begin(),vetor.end());
    int best = 10000;
	for(int i = 0; i+n <= m;i++){
		int menor = 100000;
		int maior = -1 ;
		for(int j = 0;j < n;j++){
			if(vetor[i+j]> maior)
				maior = vetor[i+j];
			if(vetor[i+j]< menor)
				menor = vetor[i+j];
		}
		best = min(best,maior - menor);
	}
	cout << best << endl;
	return 0;
}

