/*
	* AUTHOR : lo0ker
	* Problem : Increasing Array
	* source : https://cses.fi/problemset/task/1094
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
  ll cur;
  ll in;
  cin >> in;
  cur = in;
  ll ans = 0;
  for(int i = 1; i < n; i++){
    cin >> in;
    if(in < cur){
      ans += (cur - in);
    }
    else{
      cur = in;
    }
  }
  cout << ans;
	return 0;
}