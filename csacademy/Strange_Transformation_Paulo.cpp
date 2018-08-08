#include <bits/stdc++.h>
#define INF 3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN
#define MAXM
#define endl '\n'

typedef long long int ll;

using namespace std;
int va[4];
int vb[4];

struct Aux{
	long int v;
	int q2;
	int q3;	
	Aux(){
		q2=0;
		q3=0;
	}
};

set<long int> conteiner;

Aux meio[52];

int func(Aux a, Aux b){
	if(a.q2 == b.q2)
		return a.q3 < b.q3;
	return a.q2 > b.q2;
}

int main(){
	ios::sync_with_stdio(0);
	//cin.tie(0);
	
	bool certo = true;
	
	long int ca, cb;
	long int n, a, b;
	
	cin >> n >> a >> b;
	ca = a;
	cb = b;

	while(a % 2 == 0){
		va[2]++;
		a>>=1;
	}		
	
	while(a % 3 == 0){
		va[3]++;
		a/=3;
	}		

	while(b % 2 == 0){
		vb[2]++;
		b>>=1;
	}		
	
	while(b % 3 == 0){
		vb[3]++;
		b/=3;
	}		
	
	for(int i=0; i<n; i++){
		cin >> meio[i].v;
		int aux = meio[i].v;
		
		while(aux % 2 == 0){
			meio[i].q2++;
			aux>>=1;
		}		
		
		conteiner.insert(meio[i].v);
		
		while(aux % 3 == 0){
			meio[i].q3++;
			aux/=3;
		}		
		
		if((aux != a) or (meio[i].q3 < va[3]) or (meio[i].q3 > vb[3]) or (meio[i].q2 > va[2]) or (meio[i].q2 < vb[2]))
			certo = false;
	}
	
	meio[n].v = cb;
	meio[n].q2 = vb[2];
	meio[n].q3 = vb[3];
	n++;
	
	if(a != b or va[3] > vb[3] or va[2] < vb[2] or !certo){
		cout << "-1" << endl;
		return 0;
	}
	
	sort(meio, meio+n, func);
	int i=0;

	stringstream ss;
	
	ss << ca << " ";	
	conteiner.erase(ca);
	while(ca != cb){
				
		while(va[2] > meio[i].q2){
			va[2]--;
			ca>>=1;			
			ss << ca << " ";			
			conteiner.erase(ca);
			
			if(ca == cb)
				break;
		}
		
		while(meio[i].q3 > va[3]){
			va[3]++;
			ca *= 3; 
			ss << ca << " ";			
			conteiner.erase(ca);

			if(ca == cb)
				break;
		}
		
		i++;
		if(i == n)
			break;			
	}
	
	if(!conteiner.empty()){
		cout << "-1" << endl;
		return 0;		 
	}
	
	long int r;
	ss >> r;
	
	cout << r;
	
	while(ss >> r){
		cout << " " << r; 
	}
	
	cout << endl;
	
	return 0;
}
