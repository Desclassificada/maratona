#include <bits/stdc++.h>

using namespace std;
#define INF 1073741823
int memo[110][920];

bool solve(int m,int s){
	if(m == 0 && s == 0)
		return memo[m][s] = 1;
	if(s< 0)
		return 0;
	if(m == 0)
		return memo[m][s] = 0;

	if(memo[m][s] >= 0)
		return memo[m][s];
	bool vdc = false;
	for(int i = 0;i <= 9 ;i++){
		vdc |= solve(m-1,s-i);
	}
	return memo[m][s] = vdc;
}

int main() {
	int m,s;
	cin >> m >> s;
	if(s == 0 && m >1){
		cout << -1 << " " << -1 << endl;
		return 0;
	}
	
	memset(memo,-1,sizeof memo);
	solve(m,s);
	if(memo[m][s] == 0){
		cout << -1 << " " << -1 << endl;
		return 0;
	}
	int aux = s;
	for(int i = m-1; i >= 0;i--){
			for(int k = 0;k <= 9;k++){
				if(memo[i][s-k]){
					if(k == 0 && aux == s && i != 0)
						continue;
					cout << k;
					s-=k;
					
					break;
				}
			}
		}
	
	cout << " ";
	
	for(int i = m-1; i >= 0;i--){
			for(int k = 9; k>= 0;k--){
				if(aux-k < 0)
					continue;
				if(memo[i][aux-k]){
					cout << k;
					aux -=k;
					break;
				}
			}
		}
	cout << endl;
	return 0;
}
