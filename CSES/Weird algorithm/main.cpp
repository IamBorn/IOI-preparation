/*
	* AUTHOR : lo0ker
	* Problem : Weird Algorithm
	* source : https://cses.fi/problemset/task/1068
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
  while(n != 1){
    cout << n << " ";
    if(n % 2 == 0){
      n /= 2;
    }
    else{
      n = (n*3) + 1;
    }
  }
  cout << n;
	return 0;
}