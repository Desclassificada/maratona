#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define MOD 1000000007ll

#define MP make_pair
#define PB push_back
#define F first
#define S second

#define MAXN 100010
#define MAXM 
#define endl '\n'

typedef long long int ll;
typedef pair<long int, long int> pii;

bool noIsPrime[1000010];

void crivo(){
	noIsPrime[0] = true;
	noIsPrime[1] = true;
	
	for(long int i=2L; i<=1000000L; i++){
		if(!noIsPrime[i]){
			
			for(long int j=i+i; j<=1000000L; j+=i){
				noIsPrime[j] = true;
			}
		}	
	}
}

int main(){		
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	crivo();
		
	string s;
	
	while(cin >> s){
		
		long int a = stol(s);
		long int b = stol(string(s.rbegin(), s.rend()));
		
		if((!noIsPrime[a]) and (!noIsPrime[b]) and (a != b) )
			cout << a <<" is emirp."  << endl;			
		else if (!noIsPrime[a])
			cout << a <<" is prime."  << endl;			
		else
			cout << a <<" is not prime."  << endl;			
	
	}	
	
	return 0;
}
