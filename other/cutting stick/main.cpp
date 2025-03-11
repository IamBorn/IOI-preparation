/*
	* AUTHOR : lo0ker
	* Problem : Cutting stick
	* source : https://onlinejudge.org/external/100/10003.pdf
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

void func(int l){
  int n;
  cin >> n;
  vi arr(n+2);
  arr[0] = 0;
  arr[n+1] = l;
  for(int i = 1; i <= n; i++){
    cin >> arr[i];
  }

  int dp[55][55] = {};
  int opt[55][55];
  for(int i = 0; i <= n+1; i++){
    opt[i][i] = i;
    opt[i][i+1] = i;
  }


  for (int i = n; i >= 0; i--) {
        for (int j = i+2; j <= n+1; j++) {
            int mn = INT_MAX;
            int cost = arr[j] - arr[i];
            for (int k = i+1; k <= j-1; k++) {
                if (mn >= dp[i][k] + dp[k][j] + cost) {
                    opt[i][j] = k; 
                    mn = dp[i][k] + dp[k][j] + cost; 
                }
            }
            dp[i][j] = mn; 
        }
    }

  cout << "The minimum cutting is " << dp[0][n+1] << ".\n";
}

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int l;
  cin >> l;
  while(l != 0){
    func(l);

    cin >> l;
  }
	return 0;
}