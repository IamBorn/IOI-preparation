#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;

struct Segtree{
  int t[2*MAXN];

  void build(int a[], int v, int tl, int tr){
    if(tl == tr){
      t[v] = a[tl];
    }
    else{
      int tm = (tl +tr) / 2;
      build(a, v*2, tl, tm);
      build(a, v*2+1, tm+1, tr);
      t[v] = t[v*2] + t[v*2+1];
    }
  }

  void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

  int sum(int v, int l, int r, int tl, int tr){
    if(l > r) return 0;
    else if(tl == l && tr == r) return t[v];
    else{
      int tm = (tl + tr) / 2;

      return sum(v*2, l, min(r, tm), tl, tm) + sum(v*2+1, max(l, tm+1), r, tm+1, tr);
    }
  }
};

int main(){
  int n, q;
  cin >> n >> q;

  Segtree ft;
  int b[100] = {};
  ft.build(b, 1, 0, 99);

  int a, l, r;
  while(q--){
    cin >> a;
    if(a == 2){
      cin >> l >> r;
      cout << ft.sum(1, l, r, 0, 99) << "\n";
    }
    else{
      cin >> l >> r;
      ft.update(1, 0, 99, l, r);
    }
  }
}