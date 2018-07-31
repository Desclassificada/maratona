#include <bits/stdc++.h>
#define INF 3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN
#define MAXM

typedef long long int ll;

using namespace std;
string s, t;
int n;
vector<int> result;

bool res(int i){
	if(i == n)
		return true;
	
	if(s[i] == t[i])
		return res(i+1);
		
	for(int j=i+1; j<n; j++){
		if(s[j] == t[i]){
			for(int k=j-1; k >=i; k--){
				swap(s[k],s[k+1]);
				result.PB(k+1);
			}
			
			return res(i+1);
		}
	}
	
	return false;
}

int main(){
	cin >> n;
	cin >> s >> t;
	
	if(res(0)){
		cout << result.size() << endl;
				
		if(result.size() > 0){
			cout << result[0];
			
			for(int i=1; i< (int)result.size(); i++){
				cout << " " << result[i];
			}
			
			cout << endl;
		}
		
	}else{
		cout << -1 << endl;
	}
	
	return 0;
}
