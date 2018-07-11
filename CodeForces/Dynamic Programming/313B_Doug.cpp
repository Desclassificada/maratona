#include <bits/stdc++.h>

using namespace std;
#define INF 1073741823

int acc[100100];
int main() {
	string a;
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> a;
	for(int i = 1; i< a.size();i++){
		if(a[i-1] == a[i])
			acc[i]++;
		acc[i] += acc[i-1];
	}

	int m;
	cin >> m;
	for(int i = 0;i< m;i++){
		int x, y;
		cin >> x >> y;
		//cout << acc[y-1] << " " << acc[x-1] << endl;
		cout << acc[y-1] - acc[x-1] << endl;
	}
	return 0;
}

