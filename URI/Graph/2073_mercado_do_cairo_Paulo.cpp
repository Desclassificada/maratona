#include <bits/stdc++.h>
#define MAXN 1002

using namespace std;

int t[4*MAXN][4*MAXN];

int sum_y (int vx, int vy, int tly, int try_, int ly, int ry) {
	if (ly > ry)
		return 0;
	if (ly == tly && try_ == ry)
		return t[vx][vy];
	int tmy = (tly + try_)>>1;
	return max(sum_y (vx, (vy<<1), tly, tmy, ly, min(ry,tmy))
		,sum_y (vx, (vy<<1)+1, tmy+1, try_, max(ly,tmy+1), ry));
}
 
int sum_x (int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
	if (lx > rx)
		return 0;
	if (lx == tlx && trx == rx)
		return sum_y (vx, 1, 0, 999, ly, ry);
	int tmx = (tlx + trx)>>1;
	return max(sum_x ((vx<<1), tlx, tmx, lx, min(rx,tmx), ly, ry)
		,sum_x ((vx<<1)+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry));
}

void update_y (int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
	if (ly == ry) {
		if (lx == rx)
			t[vx][vy] = new_val;
		else
			t[vx][vy] = max(t[(vx<<1)][vy], t[(vx<<1)+1][vy]);
	}
	else {
		int my = (ly + ry)>>1;
		if (y <= my)
			update_y (vx, lx, rx, (vy<<1), ly, my, x, y, new_val);
		else
			update_y (vx, lx, rx, (vy<<1)+1, my+1, ry, x, y, new_val);
		t[vx][vy] = max(t[vx][(vy<<1)], t[vx][(vy<<1)+1]);
	}
}
 
void update_x (int vx, int lx, int rx, int x, int y, int new_val) {
	if (lx != rx) {
		int mx = (lx + rx)>>1;
		if (x <= mx)
			update_x ((vx<<1), lx, mx, x, y, new_val);
		else
			update_x ((vx<<1)+1, mx+1, rx, x, y, new_val);
	}
	update_y (vx, lx, rx, 1, 0, 999, x, y, new_val);
} 
int main(){	
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int test, n;
	cin >> test;
	
	while(test--){
		
		int maximo = 0;
		cin >> n;
		
		for(int i=0; i<n; i++){
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			int m = sum_x(1, 0, 999, 0, a, 0, b) + 1;			
			update_x(1, 0, 999, a, b, m);
			
			maximo = max(maximo, m);
			
		}
		
		cout << maximo << endl;
		
		memset(t, 0, sizeof(t));
	}
	
	return 0;
}
