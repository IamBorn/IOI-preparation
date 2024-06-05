/*
	* AUTHOR : lo0ker
	* Problem : Traffic Congestion
	* source : https://dmoj.ca/problem/ioi10p6io
*/

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int MxN = 1e6+5;

vi dist;
vector<ll> sum;
vector<vi> adj;

ll dfs(int i){
  for(auto j : adj[i]){
    if(dist[j] != -1) continue;

    dist[j] = dist[i]+1;
    sum[i] += dfs(j);
  }

  return sum[i];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vector<ll> a(n);
  for(auto &it : a){
    cin >> it;
  }

  adj.resize(n);
  int u, v;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  dist.resize(n, -1);
  dist[0] = 0;
  sum.resize(n);
  ll all_sum = 0;
  for(int i = 0; i < n; i++){
    sum[i] = a[i];
    all_sum += a[i];
  }
  dfs(0);
  int ans = -1;
  ll mn = LONG_LONG_MAX;
  for(int i = 0; i < n; i++){
    ll temp = -1;
    for(auto j : adj[i]){
      if(dist[j] > dist[i]){
        temp = max(temp, sum[j]);
      }
      else{
        temp = max(temp, all_sum - sum[i]);
      }
    }
    if(temp < mn){
      mn = temp;
      ans = i;
    }
  }

  cout << ans;
  return 0;
}