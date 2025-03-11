/*
	* AUTHOR : lo0ker
	* Problem : 
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

int q[2][2] = {{1, 3}, {2, 4}};

/*
3 4
1 2
*/

ll func(ll k, ll x1, ll y1, ll x2, ll y2){
  if(k == 1){
    return abs(x1 - x2) + abs(y1 - y2);
  }
  int q1, q2;
  ll p = pow(2, k-1);
  int l1 = x1 < p ? 0 : 1;
  int l2 = y1 < p ? 0 : 1;
  int r1 = x2 < p ? 0 : 1;
  int r2 = y2 < p ? 0 : 1;
  q1 = q[l1][l2];
  q2 = q[r1][r2];
  if(q1 == q2){
    return func(k-1, x1 - p*l1, y1 - p*l2, x2 - p*r1, y2 - p*r2);
  }
  else{
    if(q1 == 1){
      if(q2 == 2){
        return func(k-1, x1, y1, p-1, 0) + func(k-1, 0, 0, x2-p, y2) + 1;
      }
      else if(q2 == 3){
        return func(k-1, x1, y1, 0, p-1) + func(k-1, 0, 0, x2, y2-p) + 1;
      }
      else{
        return min(func(k-1, x1, y1, 0, p-1) + func(k-1, 0, p-1, x2-p, y2-p), func(k-1, x1, y1, p-1, 0) + func(k-1, p-1, 0, x2-p, y2-p)) + p+p;
      }
    }
    else if(q1 == 2){
      if(q2 == 1){
        return func(k-1, x2, y2, p-1, 0) + func(k-1, 0, 0, x1-p, y1) + 1;
      }
      else if(q2 == 3){
        return min(func(k-1, x1-p, y1, 0, 0) + func(k-1, 0, 0, x2, y2-p), func(k-1, x1-p, y1, p-1, p-1) + func(k-1, p-1, p-1, x2, y2-p)) + p+p;
      }
      else{
        return func(k-1, x1-p, y1, p-1, p-1) + func(k-1, p-1, 0, x2-p, y2-p) + 1;
      }
    }
    else if(q1 == 3){
      if(q2 == 1){
        swap(x1, x2);
        swap(y1, y2);
        return func(k-1, x1, y1, 0, p-1) + func(k-1, 0, 0, x2, y2-p) + 1;
      }
      else if(q2 == 2){
        swap(x1, x2);
        swap(y1, y2);
        return min(func(k-1, x1-p, y1, 0, 0) + func(k-1, 0, 0, x2, y2-p), func(k-1, x1-p, y1, p-1, p-1) + func(k-1, p-1, p-1, x2, y2-p)) + p+p;
      }
      else{
        return func(k-1, x1, y1-p, p-1, p-1) + func(k-1, 0, p-1, x2-p, y2-p);
      }
    }
    else{
      if(q2 == 1){
        return min(func(k-1, x2, y2, 0, p-1) + func(k-1, p-1, 0, x1-p, y1-p), func(k-1, x2, y2, p-1, 0) + func(k-1, 0, p-1, x1-p, y1-p)) + p+p;
      }
      else if(q2 == 2){
        swap(x1, x2);
        swap(y1, y2);
        return func(k-1, x1-p, y1, p-1, p-1) + func(k-1, p-1, 0, x2-p, y2-p) + 1;
      }
      else{
        swap(x1, x2);
        swap(y1, y2);
        return func(k-1, x1, y1-p, p-1, p-1) + func(k-1, 0, p-1, x2-p, y2-p);
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll k;
  ll x1, y1, x2, y2;
  cin >> k >> x1 >> y1 >> x2 >> y2;
  cout << func(k, x1, y1, x2, y2);
	return 0;
}