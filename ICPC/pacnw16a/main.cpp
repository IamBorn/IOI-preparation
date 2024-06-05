/*
	* AUTHOR : lo0ker
	* Problem : A - Alphabet
	* source : https://dmoj.ca/problem/pacnw16a
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

	string s;
  cin >> s;
  vector<int> v;
  int n = sz(s);
  for(int i = 0; i < n; i++){
    auto idx = lower_bound(all(v), s[i] - 'a');
    if(idx == v.end()){
      v.push_back(s[i] - 'a');
    }
    else{
      *idx = s[i]-'a';
    }
  }
  cout << 26 - sz(v) << "\n";
	return 0;
}