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

int dp[305][35];

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  vi a(n);
  for(auto &it : a) cin >> it;

  for(int i = 1; i < k; i++){
    for(int j = i-1; j < n; j++){
      int lc = 0, rc = 0;
      int md = j;
      int temp = INT_MAX;
      for(int l = j-1; l >= i-1; l--){
        temp = min(temp, dp[l][i-1] + lc + rc);

        lc += a[md] - a[l];
        while(a[j] - a[md] < a[md] - a[l] && md < j){
          lc -= a[md] - a[l];
          rc += a[j] - a[md];
          md++;
        }
      }

      dp[j][i] = temp;
    }
  }

  int ans = INT_MAX;
  for(int i = k-1; i < n; i++) ans  = min(ans, dp[i][k]);

  cout << ans;
	return 0;
}