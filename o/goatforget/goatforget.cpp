#include "goatforget.h"
#include <vector>

std::vector<std::vector<int> > recover_map(int N, int M, int Q){
  // edit this function
  std::vector<std::vector<int> > altars_map;
  int goat = 0;
  int next = talk_tae(0);
  altars_map.push_back({goat, next});
  goat = next;
  next = talk_tae(0);
  if(next != 0){
    altars_map.push_back({goat, next});
  }
  goat = next;
  return altars_map;
}