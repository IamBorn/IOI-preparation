/*
	* AUTHOR : lo0ker
	* Problem : Missing Number
	* source : https://cses.fi/problemset/task/1083
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

	ll n;
  cin >> n;
  ll sum = 0;
  ll in;
  for(int i = 1; i < n; i++){
    cin >> in;
    sum += in;
  }

  cout << (n * (n+1) / 2) - sum;
	return 0;
}