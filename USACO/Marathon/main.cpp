/*
	* AUTHOR : lo0ker
	* source : https://usaco.org/index.php?page=viewproblem2&cpid=495
*/
#define problem "marathon"

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define f first
#define s second
#define mp make_pair

const int MOD = 1e9+7;
const int INF = 1e9 + 7;
const int mx = 100005;

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

pii mat[mx];
int delta[mx*4];
int dist[mx*4];
int n;

int get_dist(int a, int b){
  return (abs(mat[a].f - mat[b].f) + abs(mat[a].s - mat[b].s));
}

void build(int rt, int tl, int tr){
  if(tl > tr) return;
  if(tl == tr){
    if(tl < n-1){
      delta[rt] = get_dist(tl, tl+1) + get_dist(tl+1, tl+2) - get_dist(tl, tl+2);
    }
    else delta[rt] = 0;
    if(tl < n){
      dist[rt] = get_dist(tl, tl+1);
    }
    else dist[rt] = 0;
    return;
  }

  int mid = (tl + tr) / 2;
  build(tr*2, tl, mid);
  build(tr*2+1, mid+1, tr);
  delta[rt] = max(delta[rt*2], delta[rt*2+1]);
  dist[rt] = dist[rt*2] + dist[rt*2+1];
}

int q_dist(int rt, int tl, int tr, int l, int r){
  if(tl > r || tr < l) return 0;
  if(l <= tl && tr <= r) return dist[rt];
  int mid = (tl + tr) / 2;
  return q_dist(rt*2, tl, mid, l, r) + q_dist(tr*2+1, mid+1, tr, l, r);
}

int q_delta(int rt, int tl, int tr, int l, int r){
  if(tl > r || tr < l) return 0;
  if(l <= tl && tr <= r) return delta[rt];
  int mid = (tl + tr) / 2;
  return max(q_delta(rt*2, tl, mid, l, r), q_delta(tr*2+1, mid+1, tr, l, r));
}

void u_dist(int rt, int tl, int tr, int l, int r){
  if (tl > r || tl < l) return;
	if (l <= tl && tr <= r) {
		if (tl >= 1 && tl < n) dist[rt] = get_dist(tl, tl + 1);
		else dist[rt] = 0;
		return;
	}
	int mid = (tl + tr) / 2;
	u_dist(rt * 2, tl, mid, l, r);
	u_dist(rt * 2 + 1, mid + 1, tr, l, r);
	dist[rt] = dist[rt * 2] + dist[rt * 2 + 1];
}

void u_delta(int rt, int tl, int tr, int l, int r){
  if (tl > r || tl < l) return;
	if (l <= tl && tr <= r) {
		if (tl >= 1 && tl < n-1) delta[tr] = get_dist(tl, tl+1) + get_dist(tl+1, tl+2) - get_dist(tl, tl+2);
		else delta[rt] = 0;
		return;
	}
	int mid = (tl + tr) / 2;
	u_delta(rt * 2, tl, mid, l, r);
	u_delta(rt * 2 + 1, mid + 1, tr, l, r);
	delta[rt] = max(delta[rt * 2], delta[rt * 2 + 1]);
}

int main(){
  setIO(problem);

  int q;
  cin >> n >> q;
  for(int i = 1; i <= n; i++){
    cin >> mat[i].f >> mat[i].s;
  }

  build(1, 1, n);
  char op;
  for(int i = 0; i < q; i++){
    cin >> op;
    if(op == 'Q'){
      int a, b;
      cin >> a >> b;
      cout << q_dist(1, 1, n, a, b) - q_delta(1, 1, n, a, b) << '\n';
    }
    else{
      int i, x, y;
      cin >> i >> x >> y;
      mat[i].f = x;
      mat[i].s = y;
      for(int j = i-1; j <= i; j++){
        u_dist(1, 1, n, j, j);
      }
      for(int j = i-1; j <= i; j++){
        u_delta(1, 1, n, j, j);
      }
    }
  }
	return 0;
}