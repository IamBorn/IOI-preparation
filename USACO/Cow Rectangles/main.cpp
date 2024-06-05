/*
	* AUTHOR : lo0ker
	* source : https://usaco.org/index.php?page=viewproblem2&cpid=514
*/
#define problem "cowrect"

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

int qsh[1005][1005] = {};
int qsb[1005][1005] = {};

int main(){
  setIO(problem);

  int n;
  cin >> n;
  vector<pii> h;
  vector<pii> g;
  for(int i = 0; i < n; i++){
    int x, y;
    char a;
    cin >> x >> y >> a;
    x++;
    y++;
    if(a == 'H'){
      h.push_back({x, y});
      qsh[x][y] = 1;
    }
    else{
      qsb[x][y] = 1;
    }
  }

  for(int i = 1; i <= 1001; i++){
    for(int j = 1; j <= 1001; j++){
      qsh[i][j] += qsh[i-1][j] + qsh[i][j-1] - qsh[i-1][j-1];
      qsb[i][j] += qsb[i-1][j] + qsb[i][j-1] - qsb[i-1][j-1];
    }
  }
  sort(all(h));

  int mxans = 1;
  int mnA = 0;
  for(int i = 0; i < sz(h); i++){
    for(int j = i+1; j < sz(h); j++){
      int x1 = max(h[i].f, h[j].f);
      int y1 = max(h[i].s, h[j].s);
      int x2 = min(h[i].f, h[j].f);
      int y2 = min(h[i].s, h[j].s);
      
      if(qsb[x1][y1] - qsb[x1][y2-1] - qsb[x2-1][y1] + qsb[x2-1][y2-1] == 0){
        int cnt = qsh[x1][y1] - qsh[x1][y2-1] - qsh[x2-1][y1] + qsh[x2-1][y2-1];
        if(cnt > mxans){
          mxans = cnt;
          mnA = (x1-x2)*(y1-y2);
        }
        else if(cnt == mxans){
          mnA = min(mnA,(x1-x2)*(y1-y2));
        }
      }
    }
  }
  cout << mxans << '\n';
  cout << mnA;
	return 0;
}