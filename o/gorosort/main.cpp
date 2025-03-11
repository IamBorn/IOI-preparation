/*
	* AUTHOR : lo0ker
	* Problem : Gorosort
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

double play(int n){
  
  int ans = 0;
  int a;
  for(int i = 1; i <= n; i++){
    cin >> a;
    if(a != i) ans++;
  }

  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
  cin >> t;
  for(int i = 1; i <= t; i++){
    cin >> n;
    cout << "Case #" << i << ": " << play(n) << ".000000\n";
  }
	return 0;
}