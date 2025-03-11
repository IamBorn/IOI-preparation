/*
	* AUTHOR : lo0ker
	* Problem : DVDs
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

const int MAXN = 100005;

int tmax[4*MAXN];
int tmin[4*MAXN];

void buildMAX(int v, int tl, int tr){
  if(tl == tr){
    tmax[v] = tl;
  }
  else{
    int tm = (tl+tr) / 2;
    buildMAX(v*2, tl, tm);
    buildMAX(v*2+1, tm+1, tr);
    tmax[v] = max(tmax[v*2], tmax[v*2+1]);
  }
}

void buildMIN(int v, int tl, int tr){
  if(tl == tr){
    tmin[v] = tl;
  }
  else{
    int tm = (tl+tr) / 2;
    buildMIN(v*2, tl, tm);
    buildMIN(v*2+1, tm+1, tr);
    tmin[v] = min(tmin[v*2], tmin[v*2+1]);
  }
}

int qmax(int v, int tl, int tr, int l, int r){
  if(l > r){
    return INT_MIN;
  }
  if(l == tl && tr == r){
    return tmax[v];
  }
  int tm = (tl + tr) / 2;
  return max(qmax(v*2, tl, tm, l, min(r, tm)), qmax(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int qmin(int v, int tl, int tr, int l, int r){
  if(l > r){
    return INT_MAX;
  }
  if(l == tl && tr == r){
    return tmin[v];
  }
  int tm = (tl + tr) / 2;
  return min(qmin(v*2, tl, tm, l, min(r, tm)), qmin(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void umax(int v, int tl, int tr, int pos, int new_val){
  if(tl == tr){
    tmax[v] = new_val;
  } 
  else{
    int tm = (tl + tr) / 2;
    if(pos <= tm)
      umax(v*2, tl, tm, pos, new_val);
    else
      umax(v*2+1, tm+1, tr, pos, new_val);
    tmax[v] = max(tmax[v*2], tmax[v*2+1]);
  }
}

void umin(int v, int tl, int tr, int pos, int new_val){
  if(tl == tr){
    tmin[v] = new_val;
  } 
  else{
    int tm = (tl + tr) / 2;
    if(pos <= tm)
      umin(v*2, tl, tm, pos, new_val);
    else
      umin(v*2+1, tm+1, tr, pos, new_val);
    tmin[v] = min(tmin[v*2], tmin[v*2+1]);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
  cin >> n >> k;

  int q, a, b;

  vi arr(n);
  for(int i = 0; i < n; i++){
    arr[i] = i;
  }
  
  buildMAX(1, 0, n-1);
  buildMIN(1, 0, n-1);
  for(int i = 0; i < k; i++){
    cin >> q >> a >> b;
    if(q == 0){
      swap(arr[a], arr[b]);

      umax(1, 0, n-1, a, arr[a]);
      umax(1, 0, n-1, b, arr[b]);
      umin(1, 0, n-1, a, arr[a]);
      umin(1, 0, n-1, b, arr[b]);
    }
    else{
      if(qmax(1, 0, n-1, a, b) == b && qmin(1, 0, n-1, a, b) == a){
        cout << "YES\n";
      }
      else{
        cout << "NO\n";
      }
    }
  }
	return 0;
}