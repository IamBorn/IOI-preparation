#include "guess.h"
#include <vector>
#include <iostream>

using namespace std;

int find_answer(int N, int K) {
  if(K == 1 || N == 729){
    vector<int> v;
    for(int i = 0; i < N; i++) v.push_back(i);
    vector<pair<int, char>> q;
    while(v.size() > 1){
      int si = v.size();
      for(int i = 0; i < si; i+= 6){
        if(i + 2 < si){
          q.push_back({v[i+2], 'R'});
        }
        if(i + 3 < si){
          q.push_back({v[i+3], 'R'});
        }
      }

      auto a = ask(q);
      q = vector<pair<int, char>>(0);
      vector<int> nv;
      for(int i = 0; i < si; i+= 6){
        if(a == 'X'){
          nv.push_back(v[i]);
          if(i + 5 < si){
            nv.push_back(v[i+5]);
          }
        }
        if(a == 'C'){
          if(i + 1 < si){
            nv.push_back(v[i+1]);
          }
          if(i + 4 < si){
            nv.push_back(v[i+4]);
          }
        }
        else{
          if(i + 2 < si){
            nv.push_back(v[i+2]);
          }
          if(i + 3 < si){
            nv.push_back(v[i+3]);
          }
        }
      }

      v = nv;
    }
    cout << v[0];
    
    return v[0];
  }
  else{

  }
}