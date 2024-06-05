/*
	* AUTHOR : lo0ker
	* Problem : Memory
	* source : https://dmoj.ca/problem/ioi10p5
*/ 

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void play(){
  vector<vi> a(26);
  for(int i = 1; i <= 50; i++){
    char temp = faceup(i);
    a[temp - 'A'].push_back(i);
  }
  for(int i = 0; i < 25; i++){
    for(auto j : a[i]){
      faceup(j);
    }
  }
}