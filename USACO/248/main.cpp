/*
	* AUTHOR : lo0ker
	* source : https://usaco.org/index.php?page=viewproblem2&cpid=647
*/
#define problem "248"

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
  setIO(problem);

  int n;
  cin >> n;
  vi a(n);
  for(auto &it : a) cin >> it;
  vector<vi> dp(n, vi(n, -1));
  int ans = -1;
  for(int i = n-1; i >= 0; i--){
    for(int j = i; j < n; j++){
      if(i == j){
        dp[i][j] = a[i];
      }

      for(int rr = i; rr < j; rr++){
        if(dp[i][rr] != -1 && dp[i][rr] == dp[rr+1][j]){
          dp[i][j] = max(dp[i][j], dp[i][rr]+1);
        }
      }
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans;
}