/*
	* AUTHOR : lo0ker
	* Problem : Mobile Phones
	* source : https://dmoj.ca/problem/ioi01p1
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

const int MOD = 1e9+7;

const int mx = 1030;

int bit[mx][mx];
int n;

void updatey(int x, int y, int delta){
	if(y == 0){
		bit[x][y] += delta;
		return;
	}

	while(y < n){
		bit[x][y] += delta;
		y += (y&-y);
	}
}

void update(int x, int y, int delta){
	if(x == 0){
		updatey(x, y, delta);
		return;
	}

	while(x < n){
		updatey(x, y, delta);
		x += (x&-x);
	}
}

int qy(int x, int y){
	if(y < 0) return 0;

	int sum = bit[x][0];
	while(y){
		sum += bit[x][y];
		y -= (y&-y);
	}
	return sum;
}

int query(int x, int y1, int y2){
	if(x < 0) return 0;

	int sum = qy(0, y2) - qy(0, y1-1);

	while(x){
		sum += qy(x, y2) - qy(x, y1-1);
		x -= (x&-x);
	}

	return sum;
}

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 2D-fenwick tree lmao
	int in;
	cin >> in >> n;
	cin >> in;
	while(in != 3){
		if(in == 1){
			int x, y;
			int a;
			cin >> x >> y >> a;
			update(x, y, a);
		}
		else if(in == 2){
			int l, r, b, t;
			cin >> l >> b >> r >> t;
			cout << query(r, b, t) - query(l-1, b, t) << "\n";
		}
		cin >> in;
	}
	return 0;
}