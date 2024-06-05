/*
	* AUTHOR : lo0ker
	* source : https://usaco.org/index.php?page=viewproblem2&cpid=598
*/
#define problem "radio"

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

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int sq(int a){
  return a*a;
}

int cost(pii a, pii b){
  return sq(a.f - b.f) + sq(a.s - b.s);
}

map<char, int> md{{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
  setIO(problem);

  int n, m;
  
  cin >> n >> m;
  vector<pii> fl(n+1);
  vector<pii> bl(m+1);
  cin >> fl[0].f >> fl[0].s;
  cin >> bl[0].f >> bl[0].s;
  string fs, bs;
  cin >> fs >> bs;
  for(int i = 0; i < n; i++){
    fl[i+1] = {fl[i].f + dx[md[fs[i]]], fl[i].s + dy[md[fs[i]]]};
  }
  for(int i = 0; i < m; i++){
    bl[i+1] = {bl[i].f + dx[md[bs[i]]], bl[i].s + dy[md[bs[i]]]};
  }

  vector<vi> dp(n+1, vi(m+1, INF));
  dp[0][0] = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      dp[i+1][j] = min(dp[i+1][j], dp[i][j] + cost(fl[i+1], bl[j]));
      dp[i][j+1] = min(dp[i][j+1], dp[i][j] + cost(fl[i], bl[j+1]));
      dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + cost(fl[i+1], bl[j+1]));
    }
  }

  cout << dp[n][m];
	return 0;
}