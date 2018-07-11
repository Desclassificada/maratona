#include <bits/stdc++.h>

using namespace std;
#define INF 1073741823
bool visited[100100];
int main(){
	string a;
	cin >> a;
	bool ab = false;
	bool ba = false;
	for(int i = 0; i < a.size()-1;i++){
		if(!visited[i] && !visited[i+1]  && a[i] == 'B' && a[i+1] == 'A'){
			ba = true;
			visited[i+1] = 1;
			visited[i] = 1;
			break;
		}
	}
	for(int i = 0; i < a.size()-1;i++){
		if(!visited[i] && !visited[i+1]  && a[i] == 'A' && a[i+1] == 'B'){
			ab = true;
			visited[i] = 1;
			visited[i+1] = 1;
			break;
		}
	}
	if(ab && ba)
		cout << "YES" << endl;
	else{
		memset(visited,0,sizeof visited);
		ab = false;
		ba = false;

		for(int i = 0; i < a.size()-1;i++){
			if(!visited[i] && !visited[i+1] && a[i] == 'A' && a[i+1] == 'B'){
				ab = true;
				visited[i] = 1;
				visited[i+1] = 1;
				break;
			}
		}
		for(int i = 0; i < a.size()-1;i++){
			if(!visited[i] && !visited[i+1] && a[i] == 'B' && a[i+1] == 'A'){
				ba = true;
				visited[i] = 1;
				visited[i+1] = 1;
				break;
			}
		}
		if(ab && ba)
			cout << "YES" << endl;
		else
			cout << "NO"  << endl;
	}
	return 0;
}

