#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vetor(n);
    for(int i = 0;i<n;i++){
        cin >> vetor[i];
    }
    int maximo = 1;
    int cont = 1;
    for(int i = 0;i < n-1;i++){
        if(vetor[i] < vetor[i+1])
            cont++;
        else
            cont = 1;
        maximo = max(maximo,cont);
    }
    cout << maximo << endl;
    return 0;
}

