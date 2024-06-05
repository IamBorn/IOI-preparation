/*
	* AUTHOR : lo0ker
	* Problem : station
	* source : https://dmoj.ca/problem/ioi14pp2
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

	int n, k;
  cin >> n >> k;
  vi a(n);
  for(auto &it : a) cin >> it;

  int ans = 0;
  for(int cur = 0; cur < n-1; ){
    int nxt = cur;
    for(int j = 1; j <= k && cur + j < n; j++){
      if(a[cur+j] == 1){
        nxt = cur + j;
      }
    }

    if(nxt == cur){
      cout << -1;
      return 0;
    }
    cur = nxt;
    ans++;
  }
  cout << ans;
	return 0;
}