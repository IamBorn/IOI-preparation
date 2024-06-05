/*
	* AUTHOR : lo0ker
	* Problem : Building Bridges
	* source : https://dmoj.ca/problem/ceoi17p4
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

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
  cin >> n;
  vector<ll> h(n+1);
  for(int i = 1; i <= n; i++){
    cin >> h[i];
  }
  vector<ll> w(n+1);
  for(int i = 1; i <= n; i++){
    cin >> w[i];
    w[i] += w[i-1];
  }

  vector<ll> dp(n+1, LLONG_MAX);
  dp[1] = 0;
  for(int i = 2; i <= n; i++){
    for(int j = i-1; j > 0; j--){
      dp[i] = min(dp[i], ((h[i] - h[j])*(h[i] - h[j])) + w[i-1] - w[j] + dp[j]);
    }
  }

  cout << dp[n];
	return 0;
}