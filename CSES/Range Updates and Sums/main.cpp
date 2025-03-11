/*
	* AUTHOR : lo0ker
	* Problem : Range Updates and Sums
	* source : https://cses.fi/problemset/task/1735
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

const int MAXN = 200005;

int t[MAXN*2];
int lzset[MAXN*2];
int lzadd[MAXN*2];

void push(int l, int r, int idx){
  if(!lzset[idx] || !lzadd[idx]) return;

  if(lzset[idx] == 0){
    t[idx] += lzadd[idx] * (r - l + 1);
    if(l != r) lzadd[idx*2] += lzadd[idx], lzadd[idx*2+1] += lzadd[idx];
    lzadd[idx] = 0;
  }
}

void build(int a[], int v, int tl, int tr){
  if(tl == tr) t[v] = a[tl];
  else{
    int tm = (tl + tr) / 2;
    build(a, v*2, tl, tm);
    build(a, v*2+1, tm+1, tr);
    t[v] = t[v*2] + t[v*2+1];
  }
}

void set_update(int v, int tl, int tr, int l, int r, int val){
  if(l > tr || r < tl) return;

  if(l <= tl && r >= tr){
    lzset[v] = val;
    push(tl, tr, v);
    return;
  }
  int tm = (tl + tr) / 2;
  set_update(v*2, tl, tm, l, r, val);
  set_update(v*2+1, tm+1, tr, l, r, val);
  t[v] = t[v*2] + t[v*2+1];
}

void add_update(int v, int tl, int tr, int l, int r, int val){

}

int sum(int v, int tl, int tr, int l, int r){
  if(l > tr || r < tl) return 0;

  push(tl, tr, v);
  if(l <= tl && r >= tr) return t[v];
  int tm = (tl + tr) / 2;
  return sum(v*2, tl, tm, l, r) + sum(v*2+1, tm+1, tr, l, r);
}

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
  cin >> n >> q;
  int arr[200005];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  build(arr, 1, 0, n-1);

  int op, a, b, x;
  while(q--){
    cin >> op;
    if(op == 1){
      cin >> a >> b >> x;
      add_update(1, 0, n-1, a, b, x);
    }
    else if(op == 2){
      cin >> a >> b >> x;
      set_update(1, 0, n-1, a, b, x);
    }
    else{
      cin >> a >> b;
      cout << sum(1, 0, n-1, a, b) << "\n";
    }
  }
	return 0;
}