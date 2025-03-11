/*
	* AUTHOR : lo0ker
	* Problem : Coding Company
	* source : https://cses.fi/problemset/task/1665
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

vi a;

ll dp[105][5005];

ll f(int n, int x){
  if(n < 0) return 1;

  if(dp[n][x] != -1) return dp[n][x];

  ll ans = 0;
  for(int i = n; i >= 0; i--){
    if(x - (a[n] - a[i]) >= 0){
      ans += f(i-1, x - (a[n] - a[i]));
      ans %= MOD;
    }
    else{
      break;
    }
  }

  return dp[n][x] = ans;
}

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  memset(dp, -1, sizeof(dp));
	int n, x;
  cin >> n >> x;
  a.resize(n);
  for(auto &it : a) cin >> it;

  sort(all(a));

  cout << f(n-1, x);
	return 0;
}