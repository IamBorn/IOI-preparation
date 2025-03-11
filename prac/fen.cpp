#include <bits/stdc++.h>

using namespace std;

struct fentree{
  int n;
  vector<int> bit;

  fentree(int n){
    this->n = n+1;
    bit.assign(n+1, 0);
  }

  fentree(vector<int> a) : fentree(a.size()) {
    for(int i = 0; i < a.size(); i++){
      add(i, a[i]);
    }
  }

  void add(int idx, int val){
    for(++idx; idx < n; idx += (idx&-idx)) bit[idx] += val;
  }

  int query(int idx){
    int res = 0;
    for(++idx; idx > 0; idx -= (idx&-idx)) res += bit[idx];

    return res;
  }

  int query(int l, int r){
    return query(r) - query(l-1);
  }
};

int main(){
  int n, q;
  cin >> n >> q;

  fentree ft(n);

  int a, l, r;
  while(q--){
    cin >> a;
    if(a == 2){
      cin >> l >> r;
      cout << ft.query(l, r) << "\n";
    }
    else{
      cin >> l >> r;
      ft.add(l, r);
    }
  }
}