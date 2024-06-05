/*
	* AUTHOR : lo0ker
	* Problem : LCS on Permutations
	* source : https://codeforces.com/gym/102951/problem/C
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
  vi a(n+1);
  vi b(n+1);
  vi pos(n+1);
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    pos[a[i]] = i;
  }
  vi v(n+1);
  for(int i = 1; i <= n; i++){ cin >> b[i]; };
  for(int i = 1; i <= n; i++){ v[i] = pos[b[i]]; }
  vi lis;
  for(int i = 1; i <= n; i++){
    int it = v[i];
    auto idx = upper_bound(all(lis), it);
    if(idx == lis.end()){
      lis.push_back(it);
    }
    else{
      *idx = it;
    }
  }
  cout << sz(lis);
	return 0;
}