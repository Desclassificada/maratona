#include <bits/stdc++.h>

using namespace std;
#define INF 1073741823

int main() {
	int n;
	cin >> n;
	int anterior, x, best = 0,cont = 0;
	cin >> anterior;
	cont = 1;
	for(int i = 1;i < n;i++){
		cin >> x;
		if(anterior <= x){
			cont++;
		}else{
			best = max(best,cont);
			cont = 1;
		}
		anterior = x;
	}
	best = max(best,cont);
	cout << best << endl;
	return 0;
}

