#include <bits/stdc++.h>

#define INF 3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN
#define MAXM

typedef long long int ll;

using namespace std;
int vetor[110];

int main(){
	vector<int> res;
	
	int n,  m;
	cin >> n >> m;
	
	for(int i =0; i <n; i++){
		int a, b;
		cin >> a >> b;
		
		for(int l=a; l <=b; l++){
			vetor[l] = 1;
		}
	}
	
	for(int i = 1; i <= m; i++){
		if(!vetor[i]){			
			res.push_back(i);
		}
	}
	
	cout << res.size() << endl;
	
	if(res.size() > 0){
		cout << res[0];
		
		for(int i=1; i< (int)res.size(); i++){
			cout << " " << res[i];
		}
		
		cout << endl;
	}
	
	return 0;
}
