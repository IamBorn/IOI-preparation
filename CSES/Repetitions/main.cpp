/*
	* AUTHOR : lo0ker
	* Problem : Repetitions
	* source : https://cses.fi/problemset/task/1069
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
  int n = sz(s);
  int cur = 1;
  int mx = 1;
  for(int i = 0; i < n-1; i++){
    if(s[i] == s[i+1]){
      cur++;
    }
    else{
      cur = 1;
    }
    mx = max(mx, cur);
  }
  cout << mx;
	return 0;
}