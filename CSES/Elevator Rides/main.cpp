/*
	* AUTHOR : lo0ker
	* Problem : Elevator Rides
	* source : https://cses.fi/problemset/task/1653
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

	int n, x;
  cin >> n >> x;
  vi weight(n+1);
  for(auto &it : weight) cin >> it;

  vector<pii> dp(1 << n, {n+1, x+1});
  dp[0] = {1, 0};
  for(int mask = 1; mask < (1 << n); mask++){
    for(int i = 0; i < n; i++){
      if(mask & (1 << i)){
        auto prev = dp[(mask ^ (1 << i))];
        int num = prev.first;
        int totalW = prev.second;

        if(totalW + weight[i] <= x){
          totalW += weight[i];
        }
        else{
          num++;
          totalW = weight[i];
        }

        dp[mask] = min(dp[mask], make_pair(num, totalW));
      }
    }
  }

  cout << dp[(1 << n) - 1].first;
	return 0;
}