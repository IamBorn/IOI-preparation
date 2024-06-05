/*
	* AUTHOR : lo0ker
	* Problem : Garage
	* source : https://dmoj.ca/problem/ioi09p5
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

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
  cin >> n >> m;
  vi rate(n);
  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i = 0; i < n; i++){
    cin >> rate[i];
    pq.push(i);
  }

  vi w(m+1);
  vi park(m+1, -1);
  for(int i = 1; i <= m; i++){
    cin >> w[i];
  }
  int in;
  int ans = 0;
  queue<int> q;
  for(int i = 0; i < m*2; i++){
    cin >> in;
    if(in > 0){
      if(pq.empty()){
        q.push(in);
      }
      else{
        int cur = pq.top();
        pq.pop();
        park[in] = cur;
        ans += (w[in] * rate[cur]);
      }
    }
    else{
      in = -in;
      pq.push(park[in]);
      if(!q.empty()){
        int temp = q.front();
        q.pop();
        int cur = pq.top();
        pq.pop();
        park[temp] = cur;
        ans += (w[temp] * rate[cur]);
      }
    }
  }
  cout << ans;
	return 0;
}