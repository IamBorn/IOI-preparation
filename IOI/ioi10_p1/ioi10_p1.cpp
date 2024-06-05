/*
	* AUTHOR : lo0ker
	* Problem : Cluedo
	* source : https://dmoj.ca/problem/ioi10p1
*/

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void Solve(){
  int a = 1, b = 1, c = 1;
  while(true){
    int r = Theory(a, b, c);
    if(r == 1) a++;
    else if(r == 2) b++;
    else if(r == 3) c++;
    else return;
  }
}