#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<long int, null_type, less<long int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

/*
	o.find_by_order(index)
	o.order_of_key(value)	
	o.find(value)
*/

#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f

#define MP make_pair
#define PB push_back
#define F first
#define S second

#define MAXN 50010
#define MAXM 500010
#define endl '\n'

#define cind(a) scanf("%lf", &a)
#define cinc(a) scanf(" %c", &a)
#define cinll(a) scanf("%lld", &a)

#define cini(a) scanf("%ld", &a)
#define cin2i(a, b) scanf("%ld %ld", &a, &b)
#define cin3i(a, b, c) scanf("%ld %ld %ld", &a, &b, &c)
#define cin4i(a, b, c, d) scanf("%ld %ld %ld %ld", &a, &b, &c, &d)
#define cin5i(a, b, c, d, e) scanf("%ld %ld %ld %ld %ld", &a, &b, &c, &d, &e)

#define coutd(a) printf("%lf", a)
#define coutdl(a) printf("%lf\n", a)
#define coutc(a) printf("%c", a)
#define coutcl(a) printf("%c\n", a)
#define coutll(a) printf("%lld", a)
#define coutlll(a) printf("%lld\n", a)

#define couti(a) printf("%ld", a)
#define coutil(a) printf("%ld\n", a)
#define cout2i(a, b) printf("%ld %ld\n", a, b)
#define cout3i(a, b, c) printf("%ld %ld %ld\n", a, b, c)
#define cout4i(a, b, c, d) printf("%ld %ld %ld %ld\n", a, b, c, d)
#define cout5i(a, b, c, d, e) printf("%ld %ld %ld %ld %ld\n", a, b, c, d, e)

#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)*(b))/__gcd((a), (b)))

typedef long long int ll;
typedef pair<long int, long int> pii;

struct node{
	long int y, v, sum, size;
	bool rev;
	node *l, *r;
	node(){
	}
	node(long int _v) : v(_v), sum(_v), y(rand()),
		size(1), l(NULL), r(NULL), rev(false) {}	
};

class ImplicitTreap {
private:
	node* root;
	int size(node* t) { return t ? t->size : 0; }
	long int sum(node* t) { return t ? t->sum : 0; }
	node* refresh(node* t) {
		if (t == NULL) return t;
		t->size = 1 + size(t->l) + size(t->r);
		t->sum = t->v + sum(t->l) + sum(t->r);
		if (t->l != NULL) t->l->rev ^= t->rev;
		if (t->r != NULL) t->r->rev ^= t->rev;
		if (t->rev) {
			swap(t->l, t->r);
			t->rev = false;
		}
		return t;
	}
	void split(node* &t, int k, node* &a, node* &b) {
		refresh(t);
		node * aux;
		if (!t) a = b = NULL;
		else if (size(t->l) < k) {
			split(t->r, k-size(t->l)-1, aux, b);
			t->r = aux;
			a = refresh(t);
		}
		else {
			split(t->l, k, a, aux);
			t->l = aux;
			b = refresh(t);
		}
	}
	node* merge(node* a, node* b) {
		refresh(a); refresh(b);
		//node* aux;
		if (!a || !b) return a ? a : b;
		if (a->y < b->y) {
			a->r = merge(a->r, b);
			return refresh(a);
		}
		else {
			b->l = merge(a, b->l);
			return refresh(b);
		}
	}
	node* at(node* t, int n) {
		if (!t) return t;
		refresh(t);
		if (n < size(t->l)) return at(t->l, n);
		else if (n == size(t->l)) return t;
		else return at(t->r, n-size(t->l)-1);
	}
	void del(node* &t) {
		if (!t) return;
		if (t->l) del(t->l);
		if (t->r) del(t->r);
		delete t;
		t = NULL;
	}
public:
	ImplicitTreap() : root(NULL) { }
	~ImplicitTreap() { clear(); }
	void clear() { del(root); }
	int size() { return size(root); }
	bool insertAt(int n, int v) {
		node *a, *b;
		split(root, n, a, b);
		root = merge(merge(a, new node(v)), b);
		return true;
	}
	bool erase(int n) {
		node *a, *b, *c, *d;
		split(root, n, a, b);
		split(b, 1, c, d);
		root = merge(a, d);
		if (c == NULL) return false;
		delete c;
		return true;
	}
	int at(int n) {
		node* ans = at(root, n);
		return ans ? ans->v : -1;
	}
	long int query(int l, int r) {
		if (l > r) swap(l, r);
		node *a, *b, *c, *d;
		split(root, l, a, d);
		split(d, r-l+1, b, c);
		long ans = sum(b);
		root = merge(a, merge(b, c));
		return ans;
	}
	void reverse(int l, int r) {
		if (l>r) swap(l, r);
		node *a, *b, *c, *d;
		split(root, l, a, d);
		split(d, r-l+1, b, c);
		if (b != NULL) b->rev ^= 1;
		root = merge(a, merge(b, c));
	}
};

int main(){	
	
	srand(time(NULL));
	ImplicitTreap treap;
	
	long int n, k;
	cini(n);
	
	for(int i=0; i<n; i++){
		long int aux;
		cini(aux);
		
		treap.insertAt(i, aux);
	}
	
	cini(k);
	
	for(int i=0; i<k; i++){
		char op;
		long int a, b;
		
		cinc(op);
		cin2i(a, b);
		
		if(op == 'I'){
			treap.insertAt(a, b);
		}else{
			coutil(treap.query(a-1, b-1));
		}
	}
	
	return 0;
}
