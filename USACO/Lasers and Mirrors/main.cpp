/*
	* AUTHOR : lo0ker
	* Problem : Lasers and Mirrors
	* source : https://usaco.org/index.php?page=viewproblem2&cpid=671
*/
#define problem "laser"

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

vector<pii> points;

map<int, vi> H;
map<int, vi> V;

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
  setIO(problem);

  int n, xl, yl, xb, yb;
  cin >> n >> xl >> yl >> xb >> yb;
  points.push_back({xl, yl});
  V[xl].push_back(0);
  H[yl].push_back(0);
  points.push_back({xb, yb});
  V[xb].push_back(1);
  H[yb].push_back(1);

  int x, y;
  for(int i = 0; i < n; i++){
    cin >> x >> y;
    points.push_back({x, y});
    V[x].push_back(i+2);
    H[y].push_back(i+2);
  }

  vector<pii> dist(n+2);
  queue<pair<pii, int>> q;
  q.push({{0, 0}, 0});
  q.push({{0, 0}, 1});
  while(!q.empty()){
    auto t = q.front();
    q.pop();
    if(dist[t.f.f] <= t.f.s){
      continue;
    }

    dist[]
  }
	return 0;
}