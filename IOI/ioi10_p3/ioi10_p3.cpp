/*
	* AUTHOR : lo0ker
	* Problem : Quality of Living
	* source : https://dmoj.ca/problem/ioi10p3io
*/

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int a[3005][3005];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int r, c, h, w;
  cin >> r >> c >> h >> w;

  for(int i = 1; i <= r; i++){
    for(int j = 1; j <= c; j++){
      cin >> a[i][j];
    }
  }

  int left = 1, right = (r*c)+1;
  while(left < right){
    int mid = (left + right) / 2;

    int q[r+1][c+1] = {};
    for(int i = 1; i <= r; i++){
      for(int j = 1; j <= c; j++){
        if(a[i][j] < mid) q[i][j] = -1;
        else if(a[i][j] > mid) q[i][j] = 1;

        q[i][j] += q[i-1][j] + q[i][j-1] - q[i-1][j-1];
      }
    }
    bool ck = false;
    for(int i = h; i <= r; i++){
      for(int j = w; j <= c; j++){
        if(q[i][j] - q[i-h][j] - q[i][j-w] + q[i-h][j-w] <= 0){
          ck = true;
          break;
        }
      }
    }
    if(ck){
      right = mid;
    }
    else{
      left = mid+1;
    }
  }
  cout << left;
  return 0;
}