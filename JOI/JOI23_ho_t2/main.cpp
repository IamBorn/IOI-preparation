/*
	* AUTHOR : lo0ker
	* Problem : Advertisement 2
	* source : https://oj.uz/problem/view/JOI23_ho_t2
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

const int MOD = 1e9+7;

struct house{
  int x, e;
};

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
  cin >> n;
  int x, e;
  vector<house> a;
  for(int i = 0; i < n; i++){
    cin >> x >> e;
    a.push_back({x, e});
  }

  priority_queue<pii> pq;
  for(int i = 0; i < n; i++){
    pq.push({a[i].e, i});
  }
  vector<bool> isV(n, false);
  int ans = 0;
  while(!pq.empty()){
    auto [ei, i] = pq.top();
    pq.pop();
    if(isV[i]) continue;
    ans++;
    for(int j = i-1; j >= 0; j--){
      if((a[i].x - a[j].x) <= (ei - a[j].e)){
        isV[j] = true;
      }
    }
    for(int j = i+1; j < n; j++){
      if((a[j].x - a[i].x) <= (ei - a[j].e)){
        isV[j] = true;
      }
    }
  }
  cout << ans;
	return 0;
}