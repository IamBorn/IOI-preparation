/*
	* AUTHOR : lo0ker
	* Problem : Deciphering the Mayan Writing
	* source : https://dmoj.ca/problem/ioi06p1
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m;
  string w, s;
  cin >> n >> m >> w >> s;
  map<char, int> mw;
  for(int i = 0; i < n; i++){
    mw[w[i]]++;
  }

  map<char, int> ms;
  queue<char> q;
  int cnt = 0;
  for(int i = 0; i < m; i++){
    q.push(s[i]);
    ms[s[i]]++;
    while(ms[s[i]] > mw[s[i]]){
      ms[q.front()]--;
      q.pop();
    }
    if(q.size() == n) cnt++;
  }
  cout << cnt;
  return 0;
}