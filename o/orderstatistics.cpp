/*
	* AUTHOR : lo0ker
	* Problem : o67_oct_orderstatistics
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

	int q;
  cin >> q;
  multiset<ll> s;
  while(q--){
    char c;
    int x;
    cin >> c >> x;
    if(c == 'I'){
      s.insert(x);
    }
    else if(c == 'O'){
      cout << distance(s.begin(), s.lower_bound(x)) << "\n";
    }
    else if(c == 'G'){
      
    }
  }
	return 0;
}