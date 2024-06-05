/*
	* AUTHOR : lo0ker
	* source : https://usaco.org/index.php?page=viewproblem2&cpid=496
*/
#define problem "cowjog"

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define f first
#define s second
#define mp make_pair

const int MOD = 1e9+7;
const int INF = 1e9 + 7;

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
  setIO(problem);

  ll n, t;
  cin >> n >> t;
  ll a, b;
  vector<ll> v(n);
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    v[i] = -(a + (b*t));
  }

  vector<ll> lis;
  ll ans = 1;
  for(int i = 0; i < n; i++){
    auto idx = upper_bound(all(lis), v[i]);
    if(idx == lis.end()){
      lis.push_back(v[i]);
    }
    else{
      *idx = v[i];
    }
  }

  cout << lis.size();
	return 0;
}