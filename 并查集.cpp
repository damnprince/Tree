#include<iostream>
using namespace std;


int f[105];
int h[105];

int maxx(int a, int b) {
	return a > b ? a : b;
}

//∑«µ›πÈ
/*
int find(int x) {
	int p = x;
	while (p = f[p]) {
		p = f[p];
	}
	return p;
}
*/

//µ›πÈ
int find(int x) {
	if (x == f[x])return x;
	else {//—πÀı¬∑æ∂
		int p = find(f[x]);
		f[x] = p;
		return p;
	}
}

int main() {
	int n, q;
	int opt,x,y;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) f[i] = i, h[i] = 1;
	for (int i = 1; i <= q; i++) {
		cin >> opt>>x>>y;
		if (opt == 1) {
			//∫œ≤¢
			int rx, ry;
			rx = find(x);
			ry = find(y);
			f[ry] = rx;
			/*
			if (h[rx] >= h[ry]) {
				f[ry] = rx;
				h[rx] = maxx(h[rx], h[ry] + 1);
			}
			else {
				f[rx] = ry;
				h[ry] = maxx(h[ry], h[rx] + 1);
			}
			*/
		}
		else {
			//≤È—Ø
			int rx, ry;
			rx = find(x);
			ry = find(y);
			if (rx == ry)cout << "yes!" << endl;
			else cout << "no" << endl;
			
		}
	}
	return 0;
}
/*
4 4
1 1 2
1 2 3
2 1 3
2 2 6

*/