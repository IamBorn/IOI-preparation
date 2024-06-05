/*
	* AUTHOR : lo0ker
	* Problem : Salad Bar
	* source : https://szkopul.edu.pl/problemset/problem/d30xri2XGeuQ45CDrB7DWijK/site/?key=statement
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
  vector<int> a(n);
  string s;
  cin >> s;
  for(int i = 0; i < n; i++){
    a[i] = (s[i] == 'p') ? 1 : -1;
  }
  int st = 0;
  int cnt = 0, ans = 0;
  int sum = 0;
  for(int cur = 0; cur < n; cur++){
    sum += a[cur];
    if(sum < 0){
      sum -= a[st];
      if(sum < 0){
        sum = 0;
        st = cur;
        cnt = 0;
      }
      else{
        st++;
        cnt--;
      }
    }
    else{
      cnt++;
    }

    ans = max(ans, cnt);
  }

  st = n-1;
  cnt = 0;
  sum = 0;
  for(int cur = n-1; cur >= 0; cur--){
    sum += a[cur];
    if(sum < 0){
      sum -= a[st];
      if(sum < 0){
        sum = 0;
        st = cur;
        cnt = 0;
      }
      else{
        st++;
        cnt--;
      }
    }
    else{
      cnt++;
    }

    ans = max(ans, cnt);
  }

  

  cout << ans;
	return 0;
}