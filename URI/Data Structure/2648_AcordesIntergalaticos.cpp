#include <bits/stdc++.h>
#define MAXN 10100
#define INF 0x3f3f3f3f

using namespace std;

struct No{
	int vetor[9];
	
	No(){
		vetor[0] = 0;
		vetor[1] = 0;
		vetor[2] = 0;
		vetor[3] = 0;
		vetor[4] = 0;
		vetor[5] = 0;
		vetor[6] = 0;
		vetor[7] = 0;
		vetor[8] = 0;
	}

};

const No neutral; //comp(x, neutral) = x

No comp(No a, No b) {
	No res;
	
	for(int i=0; i<9; i++){
		res.vetor[i] = a.vetor[i] + b.vetor[i];
	}
	
	return res;
}

class SegmentTree {
private:
	vector<No> st;
	vector<int> lazy;
	int size;
	
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)

	void build(int p, int l, int r, int* A) {
		if (l == r) { st[p].vetor[1] = A[l]; return; }
		int m = (l + r) / 2;
		build(left(p), l, m, A);
		build(right(p), m+1, r, A);
		st[p] = comp(st[left(p)], st[right(p)]);
	}
	
	void push(int p, int l, int r) {
		
		No novo;
		for(int i=0; i<9; i++){
			novo.vetor[(i+lazy[p])%9] = st[p].vetor[i];
			//st[p] += (r-l+1)*lazy[p];	    //Caso RSQ
			//st[p] += lazy[p]; 		    //Caso RMQ			
		} 
		
		st[p] = novo;
		
		if (l != r) {			
			lazy[right(p)] += lazy[p];
			lazy[left(p)] += lazy[p];
		}
		
		lazy[p] = 0;
	}
	
	void update(int p, int l, int r, int a, int b, int k) {
		push(p, l, r);
		if (a > r || b < l) return;
		else if (l >= a && r <= b) {
			lazy[p] = k; push(p, l, r); return;
		}		
		update(left(p), l, (l + r) / 2, a, b, k);
		update(right(p), (l + r) / 2 + 1, r, a, b, k);
		st[p] = comp(st[left(p)], st[right(p)]);
	}
	
	No query(int p, int l, int r, int a, int b) {
		push(p, l, r);
		if (a > r || b < l) return neutral;
		if (l >= a && r <= b) return st[p];
		int m = (l + r) / 2;
		No p1 = query(left(p), l, m, a, b);
		No p2 = query(right(p), m+1, r, a, b);
		return comp(p1, p2);
	}
	
public:
	SegmentTree(int* st, int* en) {
		size = (int)(en - st);
		this->st.assign(4 * size, neutral);
		lazy.assign(4 * size, 0);
		build(1, 0, size - 1, st);
	}
	
	No query(int a, int b) { return query(1, 0, size - 1, a, b); }
	void update(int a, int b, int k) { update(1, 0, size - 1, a, b, k); }
};

int init[100100];
int n, q;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    
    for(int i=0; i<n; i++)
		init[i] = 1;
    
    SegmentTree st(init, init + n); 
    
    for(int i=0; i<q; i++){
		int a, b;
		
		cin >> a >> b;
		
		No res = st.query(a, b);
		int maior = 0;
		int v	  = 0;
		
		for(int j=0; j<9; j++){
			if(res.vetor[j] >= maior){
				maior = res.vetor[j];
				v = j;
			}
		}
		
		st.update(a, b, v);
	}
		
	for(int i=0; i<n; i++){
		No res = st.query(i, i);
				
		for(int j=0; j<9; j++){
			if(res.vetor[j] == 1){
				cout << j << endl;
				break;
			}
		}
				
	}
    
	return 0;
}
