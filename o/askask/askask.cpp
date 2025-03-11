#include "askask.h"
#include <vector>

using namespace std;

std::vector<int> find_bombs(int N){
  vector<vector<int>> ans;
  int now = 2;
  for(; now <= N; now*=2){
    vector<int> temp;
    for(int i = 0; i < N; i++){
      if(i % now) temp.push_back(i);
    }
    ans.push_back(temp);
  }

  auto res = analyse(ans);
  now = 1;
  int a = 0;
  for(auto i : res){
    a += (i==true) * now;
    now *=2;
  }
  return {a, a};
}