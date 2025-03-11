/*
	* AUTHOR : lo0ker
	* Problem : Light
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

struct FenwickTree{
  vi bit;
  int n;

  FenwickTree(int n){
    this->n = n;
    bit.assign(n, 0);
  }

   FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
      for (size_t i = 0; i < a.size(); i++)
        add(i, a[i]);
    }

    int sum(int r) {
      int ret = 0;
      for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += bit[r];
      return ret;
    }

    int sum(int l, int r) {
      return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
      for (; idx < n; idx = idx | (idx + 1))
        bit[idx] += delta;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll l;
  int n;
  cin >> l >> n;
  vector<ll> v(n);
  for(auto &it : v) cin >> it;
  auto a = v;
  a.push_back(0);
  a.push_back(l);
  sort(all(a));

  
	return 0;
}