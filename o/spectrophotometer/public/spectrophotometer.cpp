#include "spectrophotometer.h"

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