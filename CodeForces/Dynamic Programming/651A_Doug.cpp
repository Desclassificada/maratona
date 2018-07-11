#include <bits/stdc++.h>

using namespace std;
#define INF 1073741823
int main(){
	int a, b;
	cin >> a >> b;
	int cont = 0;
	while(a != 0 || b != 0){
		if(a-2 > 0){
			b+=1;
			a-=2;
			cont++;
		}else if(b-2 > 0){
			b-=2;
			a+=1;
			cont++;
		}else{
			if(a-2 == 0 || b-2 == 0)
				cont++;
			break;
		}
	}
	cout << cont << endl;

	return 0;
}

