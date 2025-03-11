/*
	* AUTHOR : lo0ker
	* Problem : Marching
	* source : 
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

const int MOD = 1e9+7;

ll arr[1505][1505];

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c;
  cin >> r >> c;

  for(int i = 1; i <= r; i++){
    for(int j = 1; j <= c; j++){
      cin >> arr[i][j];
    }
  }

  vector<vi> dp11(r+2, vi(c+2, INT_MAX));
  vector<vi> dp12(r+2, vi(c+2, INT_MAX));
  vector<vi> dp21(r+2, vi(c+2, INT_MAX));
  vector<vi> dp22(r+2, vi(c+2, INT_MAX));

  dp11[1][1] = arr[1][1];
  dp12[r][c] = arr[r][c];
  dp21[r][1] = arr[r][1];
  dp22[1][c] = arr[1][c];

  for(int i = 1; i <= r; i++){
    for(int j = 1; j <= c; j++){
      if(i == 1 && j == 1) continue;
      dp11[i][j] = min(dp11[i-1][j], dp11[i][j-1]) + arr[i][j];
    }
  }

  for(int i = r; i > 0; i--){
    for(int j = c; j > 0; j--){
      if(i == r && j == c) continue;
      dp12[i][j] = min(dp12[i+1][j], dp12[i][j+1]) + arr[i][j];
    }
  }

  for(int i = r; i > 0; i--){
    for(int j = 1; j <= c; j++){
      if(i == r && j == 1) continue;
      dp21[i][j] = min(dp21[i+1][j], dp21[i][j-1]) + arr[i][j];
    }
  }

  for(int i = 1; i <= r; i++){
    for(int j = c; j > 0; j--){
      if(i == 1 && j == c) continue;
      dp22[i][j] = min(dp22[i-1][j], dp22[i][j+1]) + arr[i][j];
    }
  }

  for(int i = 1; i <= r; i++){
    for(int j = 1; j <= c; j++){
      dp11[i][j] += dp21[i][j];
      dp12[i][j] += dp22[i][j];
    }
  }

  ll ans = INT_MAX;
  ll sum;
  for(int i = 1; i <= r; i++){
    for(int j = 1; j <= c; j++){
      sum = 0;
      for(int k = j; k <= c; k++){
        sum += arr[i][k];
        ans = min(ans, dp11[i][j] + dp12[i][k] + sum - (2*arr[i][j]) - (2*arr[i][k]));
      }
      
    }
  }

  cout << ans;
	return 0;
}