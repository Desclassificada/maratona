#include <bits/stdc++.h>

using namespace std;
#define INF 1073741823

int main() {
	int m,s;
	cin >> m >> s;
	if(s == 0 && m >1){
		cout << -1 << " " << -1 << endl;
		return 0;
	}
	
	bitset<910> memo[110];

	memo[0][0] = 1; // o resto é igual a 0, não tem problema
	for (int i = 1; i <= m; i++)
	for (int k = 0; k <= 9; k++)
	memo[i] |= (memo[i-1] << k);
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

