#include "mergedmedian.h"

long long find_merged_median(int N) {
  int al = 0, ar = N, bl = 0, br = N-1;

  while(al <= ar && bl <= br){
    int am = (al + ar) / 2;
    int bm = (bl + br) / 2;

    int arrm = alice(am);
    int brrm = bob(bm);

    if(arrm == brrm){
      
    }
  }
}