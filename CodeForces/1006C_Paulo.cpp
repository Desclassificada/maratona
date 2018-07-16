#include <bits/stdc++.h>

using namespace std;
long long int vetor[200100];

int main(){
	long int n;
	cin >> n;
	
	for(long int i=0; i<n; i++){
		cin >> vetor[i];
	}
	
	long int a = 0, b = n-1;
	long long int sa = 0, sb = 0;
	
	long long int maximo = 0;
	
	while(a <= b){
		if(sa < sb){
			sa += vetor[a++];			
		}else if(sa > sb){
			sb += vetor[b--];						
		}else{
			maximo = sa;
			sa += vetor[a++];
		}
	}
	
	if(sa == sb)
		maximo = sa;

	cout << maximo << endl;
	
    return 0;
}

