/*
	* AUTHOR : lo0ker
	* Problem : Global warming
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

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
  ll x;
  cin >> n >> x;
  vector<ll> v(n);
  vector<ll> revv(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
    revv[i] = 0-v[i];
  }

  vi pre(n, 0);
  vi suff(n, 0);

  vector<ll> temp(n, INT_MAX);
  int ans = 0;
  
  for(int i = 0; i < n; i++){
    int idx = lower_bound(temp.begin(), temp.end(), v[i]) - temp.begin();
    temp[idx] = v[i];
    pre[i] = idx+1;
    ans = max(ans, pre[i]);
  }

  temp = vector<ll>(n, INT_MAX);
  for(int i = n-1; i >= 0; i--){
    int idx = lower_bound(temp.begin(), temp.end(), revv[i] + x) - temp.begin();
    ans = max(ans, pre[i] + idx);
    int in = lower_bound(temp.begin(), temp.end(), revv[i]) - temp.begin();
    temp[in] = revv[i];
  }

  cout << ans;
	return 0;
}