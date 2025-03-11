#include "garden.h"
#include "gardenlib.h"
#include <bits/stdc++.h>

using namespace std;

void count_routes(int N, int M, int P, int R[][2], int Q, int G[])
{
  int k = G[0];

  vector<vector<int>> adj(N);
  for(int i = 0 ; i < M; i++){
    adj[R[i][0]].push_back(R[i][1]);
    adj[R[i][1]].push_back(R[i][0]);
  }
  int ans = 0;

  for(int i = 0; i < N; i++){
    int curr = i;
    int prev = -1;
    int len = 0;
    while(len < k){
      int si = adj[i].size();
      bool pass = false;
      for(int j = 0; j < min(si, 2); j++){
        if(adj[i][j] != prev){
          pass = true;
          prev = curr;
          curr = adj[i][j];
          break;
        }
      }
      if(!pass) break;
    }

    if(len == k) ans++;
  }

  answer(ans);
}


