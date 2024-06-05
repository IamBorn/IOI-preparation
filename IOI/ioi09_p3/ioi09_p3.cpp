/*
	* AUTHOR : lo0ker
	* Problem : POI
	* source : https://dmoj.ca/problem/ioi09p3
*/

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 1e17;
const int MOD = 1e9+7;

struct con{
  int all_score;
  int num_solved;
  int id;

  bool operator<(const con& b){
    if(all_score != b.all_score){
      return all_score > b.all_score;
    }
    if(num_solved != b.num_solved){
      return num_solved > b.num_solved;
    }
    return id < b.id;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, t, p;
  cin >> n >> t >> p;
  p--;
  int in;
  vector<vi> solved(n+1, vi(t));
  vector<con> cons(n);
  vi score(t, 0);
  for(int i = 0; i < n; i++){
    cons[i].id = i;
    for(int j = 0; j < t; j++){
      cin >> solved[i][j];
      if(solved[i][j] == 0) {
        score[j]++;
      }
      cons[i].num_solved += solved[i][j];
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < t; j++){
      if(solved[i][j]){
        cons[i].all_score += score[j];
      }
    }
  }

  sort(all(cons));
  for(int i = 0; i < n; i++){
    //cout << cons[i].all_score << " " << cons[i].num_solved << " " << cons[i].id << '\n';
    if(cons[i].id == p){
      cout << cons[i].all_score << " " << i+1;
      break;
    }
  }
  return 0;
}