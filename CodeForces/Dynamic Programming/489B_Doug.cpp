#include<bits/stdc++.h>
using namespace std;
int vdc[10000];

int main(){
	int b, g;
	cin >> b;
	vector <int> boys(b);
	for(int i = 0; i < b; i++){
		cin >> boys[i];
	}
	cin >> g;
	vector <int> girls(g);
	for(int i = 0; i < g; i++){
		cin >> girls[i];
	}
	sort(boys.begin(),boys.end());
	sort(girls.begin(),girls.end());
	int ans = 0;
	for(int i = 0; i < b; i++){
		for(int j = 0; j < g; j++){
			if(abs(boys[i]-girls[j]) <= 1){
				girls[j] = 10000;
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;
return 0;
}
