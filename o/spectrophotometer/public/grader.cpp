#include "spectrophotometer.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

static std::vector<int> lasers;
static int N;
static int swap_count;

void fail(std::string reason) {
  std::cout << reason << std::endl;
  exit(0);
}

void success() {
  std::cout << "correct answer" << std::endl;
  std::cout << swap_count << std::endl;
  exit(0);
}

bool call_swap(int a, int b) {
  if (a < 0 || a >= 3 * N || b < 0 || b >= 3 * N || a == b) {
    fail("invalid swap parameters");
  }
  swap_count++;
  std::swap(lasers[a], lasers[b]);
  return lasers[a] == lasers[b];
}

void sort_lasers(int N) {
  int l, r;
  l = 0;
  r = N;
  int maxn = 3*N;

  while(r < maxn-1){
    if(call_swap(r, r+1)){
      while(call_swap(r, l++));
    }
    r++;
  }
  while(l < N){
    if(!call_swap(r, l++)){
      break;
    }
  }

  l = N;
  r = 2*N;

  while(r < maxn-1){
    if(call_swap(r, r+1)){
      while(call_swap(r, l++));
    }
    r++;
  }
  while(l < 2*N){
    if(!call_swap(r, l++)){
      break;
    }
  }
}

int main() {
  std::cin >> N;
  std::map<int, int> tcount;
  for (int i = 0; i < 3 * N; i++) {
    int col;
    std::cin >> col;
    tcount[col]++;
    lasers.push_back(col);
  }
  swap_count = 0;
  sort_lasers(N);
  std::map<int, int> last;
  for (auto t : tcount)
    last[t.first] = -1;
  for (int i = 0; i < 3 * N; i++) {
    if (last[lasers[i]] == -1) {
      last[lasers[i]] = i;
    } else if (last[lasers[i]] == i - 1) {
      last[lasers[i]] = i;
    } else {
      std::cout << "wrong answer" << std::endl;
      for (int i = 0; i < 3 * N; i++) {
        std::cout << lasers[i] << " ";
      }
      std::cout << std::endl;
      exit(0);
    }
  }
  success();
  return 0;
}