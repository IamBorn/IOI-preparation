/*
	* AUTHOR : lo0ker
	* Problem : 555 Bread
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
  cin >> n;
  vi arr(n);
  vector<vi> cord(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    cord[arr[i]].push_back(i);
  }

  int cnt[100005] = {};
  ll ans = 0;
  for(int i = 0; i < n; i++){
    cnt[arr[i]]++;
    if(cnt[arr[i]] >= 5){
      if(cord[arr[i]].size() > cnt[arr[i]]){
        ans += cord[arr[i]][cnt[arr[i]]] - i;
      }
      else{
        ans += n - i;
      }
    }
  }
  cout << ans;
	return 0;
}