#include <bits/stdc++.h>

using namespace std;
#define INF 1073741823
bool compara(pair<int,int>a,pair<int,int>b){
	return a.first<b.first;
}
bool compara2(pair<int,int>a,pair<int,int>b){
	return a.second<b.second;
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pair<int,int> > vetor(n);
		for(int i = 0;i < n;i++){
			cin >> vetor[i].second;
			vetor[i].first = 1;
			
		}
		sort(vetor.begin(),vetor.end(),compara2);
		for(int i = 1;i < n ;i++){
			if(vetor[i].second == vetor[i-1].second){
				vetor[i].first = vetor[i].first + vetor[i-1	].first;
				vetor[i-1].first = -1;
			}
		}
		sort(vetor.begin(),vetor.end(),compara);
		int i = 0;
		while(vetor[i].first <= 0){
			i++;
		
		}
		int result = vetor[n-1].first - vetor[i].first;	
		if(result>0)
			cout << result << endl;
		else
			cout << -1 << endl;
		
	}
	return 0;
}
