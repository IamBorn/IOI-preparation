#include "quality.h"
#include <vector>

using namespace std;

int rectangle(int r, int c, int h, int w, int Q[3001][3001]) {
	int left = 1, right = (r*c)+1;
  while(left < right){
    int mid = (left + right) / 2;
		vector<vector<int>> q(r+1, vector<int>(c+1, 0));
    for(int i = 1; i <= r; i++){
      for(int j = 1; j <= c; j++){
        if(Q[i][j] < mid) q[i][j] = -1;
        else if(Q[i][j] > mid) q[i][j] = 1;

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
  
  return left;
}
