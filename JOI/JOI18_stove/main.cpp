/*
	* AUTHOR : lo0ker
	* Problem : Stove
	* source : https://oj.uz/problem/view/JOI18_stove
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
  vi b;
  for(int i = 1; i < n; i++){
    b.pb(a[i] - a[i-1]);
  }

  sort(all(b), greater<int>());
  ll ans = a[n-1] - a[0] + 1;
  for(int i = 0; i < k-1; i++){
    ans -= (b[i]-1);
  }
  cout << ans;
	return 0;
}