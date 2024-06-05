/*
	* AUTHOR : lo0ker
	* Problem : Bit Strings
	* source : https://cses.fi/problemset/task/1617
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

ll f(int n){
  if(n == 0){
    return 1;
  }
  if(n == 1){
    return 2;
  }

  ll temp = f(n/2);
  if(n % 2 == 1){
    return (temp * temp * 2) % MOD;
  }
  else{
    return (temp * temp) % MOD;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  int n;
  cin >> n;
  cout << f(n);
	return 0;
}