/*
	* AUTHOR : lo0ker
	* Problem : 
	* source : 
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

int dp[3005];

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  memset(dp, -1, sizeof(dp));

	int n, k;
  cin >> n >> k;

  vi a(n);
  for(auto &it : a) cin >> it;

  for(int i = 0; i < n; i++){
    int temp = INT_MAX;
    for(int j = 1; j < k; j++){
      if(dp[i-j] == -1) continue;

      temp = min(temp, dp[i-j]);
    }

    dp[i] = temp + a[i];
  }

  int ans = INT_MAX;

  for(int i = 0; i < k-1; i++){
    ans = min(ans, dp[n-i-1]);
  }
  cout << ans;
	return 0;
}