/*
	* AUTHOR : lo0ker
	* Problem : Foehn Phenomena
	* source : https://oj.uz/problem/view/JOI17_foehn_phenomena
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
  vector<ll> val;
  int n;

  FenwickTree(int n){
    val.resize(n);
    this->n = n;
  }

  void update(int idx, int delta){
    for(; idx < n; idx |= (idx+1)){
      val[idx] += delta;
    }
  }

  ll query(int idx){
    ll ret = 0;
    for(; idx >= 0; idx = (idx&(idx+1))-1){
      ret += val[idx];
    }
    return ret;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
  ll s, t;
  cin >> n >> q >> s >> t;

  vector<ll> a(n+1);
  for(auto &it : a) cin >> it;

  ll ans = 0;

  

  for(int i = 0; i < n; i++){
    if(a[i] < a[i+1]){
      ans -= s*(a[i+1] - a[i]);
    }
    else{
      ans += t*(a[i] - a[i+1]);
    }
  }

  FenwickTree ftree(n+1);

  int l, r;
  ll x;
  for(int j = 0; j < q; j++){
    cin >> l >> r >> x;

    ll prev = 0;
    ll al1 = a[l-1] + ftree.query(l-1);
    ll al2 = a[l] + ftree.query(l);
    ll temp = al1 - al2;
    prev += (temp < 0) ? s*(temp) : t*(temp);
    if(r < n){
      ll ar1 = a[r] + ftree.query(r);
      ll ar2 = a[r+1] + ftree.query(r+1);
      temp = ar1 - ar2;
      prev += (temp < 0) ? s*(temp) : t*(temp);
    }
    
    ans -= prev;
    ftree.update(l, x);
    ftree.update(r+1, -x);

    al1 = a[l-1] + ftree.query(l-1);
    al2 = a[l] + ftree.query(l);
    temp = al1 - al2;
    ans += (temp < 0) ? s*(temp) : t*(temp);
    if(r < n){
      ll ar1 = a[r] + ftree.query(r);
      ll ar2 = a[r+1] + ftree.query(r+1);
      temp = ar1 - ar2;
      ans += (temp < 0) ? s*(temp) : t*(temp);
    }
    cout << ans << "\n";
    /*for(int i = 0; i <= n; i++){
      cout << a[i] + ftree.query(i) << " ";
    }
    cout << "\n";*/
  }
	return 0;
}