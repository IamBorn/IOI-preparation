/*
	* AUTHOR : lo0ker
	* Problem : DQUERY
	* source : https://www.spoj.com/problems/DQUERY/
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
const int MAXN = 30005;

vi t[MAXN*2];

void build(int a[], int v, int tl, int tr){
  if(tl == tr){
    t[v].push_back(a[tl]);
  }
  else{
    int tm = (tl + tr) / 2;
    build(a, v*2, tl, tm);
    build(a, v*2+1, tm+1, tr);
    merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(), back_inserter(t[v]));
  }
}

vector<int> query(int v, int tl, int tr, int l, int r){
  if(l > r) return vi(0);
  else if(tl == l && tr == r) return t[v];
  else{
    int tm = (tl + tr) / 2;
    vi t1 = query(v*2, tl, tm, l, min(r, tm));
    vi t2 = query(v*2, tm+1, tr, max(l, tm+1), r);
    vi temp;
    merge(t1.begin(), t1.end(), t2.begin(), t2.end(), back_inserter(temp));
    return temp;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  int n;
  cin >> n;
  int a[MAXN];
  for(int i = 0; i < n; i++) cin >> a[i];
  build(a, 1, 0, n-1);
  int q;
  cin >> q;
  int l, r;
  while(q--){
    cin >> l >> r;
    auto temp = query(1, 0, n-1, l-1, r-1);
    for(auto it : temp) cout << it << " ";
    cout << "\n";
  }
	return 0;
}