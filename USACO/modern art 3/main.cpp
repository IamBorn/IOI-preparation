/*
	* AUTHOR : lo0ker
	* Problem : Modern Art 3
	* source : https://usaco.org/index.php?page=viewproblem2&cpid=1114
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
  cin >> n;
  vi a(n+1);
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }

  vector<vi> dp(n+1, vi(n+1, INT_MAX));
  for(int i = n; i > 0; i--){
    for(int j = i; j <= n; j++){
      if(i == j) dp[i][j] = 1;

      if(a[i] == a[j]){
        for(int k = i; k < j; k++){
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] - 1);
        }
      }
      else{
        for(int k = i; k < j; k++){
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
        }
      }
    }
  }

  cout << dp[1][n];
}