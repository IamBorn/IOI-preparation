/*
	* AUTHOR : lo0ker
	* Problem : 
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

	multiset<int, greater<int>> s;
  s.insert(1);
  s.insert(1);
  s.insert(5);
  s.insert(4);
  s.insert(7);
  s.insert(11);
  s.insert(5);
  //cout << *s.begin();

  s.erase(s.find(1));
  s.erase(s.find(1));
  for(auto i : s) cout << i << " ";
	return 0;
}