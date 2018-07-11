#include <bits/stdc++.h>

using namespace std;

int main(){
    long int t;
    cin >> t;
    int i = 1;
    while(t--){
    	vector<int> vetor(3);
    	cin >> vetor[0];
    	cin >> vetor[1];
    	cin >> vetor[2];
    	sort(vetor.begin(),vetor.end());
    	cout << "Case " << i++ << ": " << vetor[1] << endl;

    }
    return 0;
}

