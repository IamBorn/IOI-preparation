#include "askask.h"
#include <vector>
#include <iostream>
#include <algorithm>

int x_1, x_2;
int n, q;

using namespace std;

std::vector<bool> analyse(std::vector<std::vector<int>> Z){
  q = Z.size();
  if(q > n){
    std::cout << "Invalid Query: too many queries" << std::endl;
    exit(0);
  }
  std::vector<bool> output;
  output.reserve(q);
  for(std::vector<int>& S : Z){
    if(S.size() > n){
      std::cout << "Invalid Query: invalid query" << std::endl;
      exit(0);
    }
    sort(S.begin(), S.end());
    int last = -1;
    bool found = false;
    for(int y : S){
      if(last != -1 && last == y){
        std::cout << "Invalid Query: invalid query" << std::endl;
        exit(0);
      }
      if(y < 0 || y >= n){
        std::cout << "Invalid Query: invalid query" << std::endl;
        exit(0);
      }
      last = y;
      if(y == x_1 || y == x_2) found = true;
    }
    output.push_back(found);
  }
  return output;
}

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

int main(){
  std::ios::sync_with_stdio(false);
  std::cin >> n >> x_1 >> x_2;
  if(x_1 > x_2) std::swap(x_1, x_2);
  std::vector<int> output = find_bombs(n);
  if(output.size() != 2){
    std::cout << "Wrong Answer: output size is not 2" << std::endl;
    exit(0);
  }
  if(output[0] != x_1 || output[1] != x_2){
    std::cout << "Wrong Answer: expected " << x_1 << " " << x_2 << " but found " << output[0] << " " << output[1] << std::endl;
    exit(0);
  }
  std::cout << "Correct Answer: " << q << std::endl;
  return 0;
}