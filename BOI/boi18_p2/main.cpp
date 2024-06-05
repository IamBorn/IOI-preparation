/*
	* AUTHOR : lo0ker
	* Problem : Martian DNA
	* source : https://dmoj.ca/problem/btoi18p2
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

int cur[200005];
int req[200005];

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, re;
  cin >> n >> k >> re;
  
  vi a(n);
  for(auto &it : a) cin >> it;

  int b, q;
  for(int i = 0; i < re; i++){
    cin >> b >> q;
    req[b] = q;
  }
  int full = 0;
  int ans = INT_MAX;
  bool can = false;
  int l;
  int r;
  l = 0;
  r = -1;
  while(l < n && r < n-1){
    //cout << l << " " << r << "\n";
    if(full < re){
      r++;
      //cout << r << "\n";
      cur[a[r]]++;
      if(cur[a[r]] == req[a[r]]) full++;
    }

    if(full == re){
      ans = min(ans, r - l + 1);
      can = true;
      cur[a[l]]--;
      if(cur[a[l]] < req[a[l]]) full--;
      l++;
    }
    //cout << full << "\n";
  }
  if(!can){
    cout << "impossible\n";
  }
  else{
    cout << ans << "\n";
  }
	return 0;
}