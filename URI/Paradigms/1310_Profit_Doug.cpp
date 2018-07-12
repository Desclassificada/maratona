#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin >> n){
    	int custo;
    	cin >> custo;
    	vector<long long int> acc(n+1);
    	acc[0]= 0 ;
    	for(int i = 1;i <= n;i++){
    		cin >> acc[i];
    		acc[i] -= custo;
    		acc[i] += acc[i-1];
    	}
    	long long int best = 0;
    	for(int i = 0;i < n;i++){
    		for(int j = i;j < n;j++){
    			best = max(best,acc[j+1]-acc[i]);
    		}
    	}
    	cout << best << endl;
    }
    return 0;
}

