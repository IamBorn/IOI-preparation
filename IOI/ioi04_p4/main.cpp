/*
	* AUTHOR : lo0ker
	* Problem : Phidas
	* source : https://dmoj.ca/problem/ioi04p4
*/

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int INF = 1e9+1;

int dp[605][605];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int w, h;
  cin >> w >> h;
  int n;
  cin >> n;
  vector<pii> a(n);
  for(int i = 1; i <= w; i++){
    for(int j = 1; j <= h; j++){
      dp[i][j] = i*j;
    }
  }
  for(auto &it : a){
    cin >> it.first >> it.second;
    dp[it.first][it.second] = 0;
  } 

  for(int i = 1; i <= w; i++){
    for(int j = 1; j <= h; j++){
      for(int k = 1; k < max(i, j); k++){
        if(k < i){
          dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
        }
        if(k < j){
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
        }
      }
    }
  }

  cout << dp[w][h];
  return 0;
}