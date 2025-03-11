/*
	* AUTHOR : lo0ker
	* Problem : Patrol
	* source : https://dmoj.ca/problem/apio10p2
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

int dia = 0;
vector<vi> adj(100005);

int func(int x, vi &isV){
  isV[x] = true;
  priority_queue<int> pq;
  for(auto i : adj[x]){
    if(!isV[i]){
      pq.push(func(i, isV));
    }
  }
  if(pq.empty()){
    return 0;
  }
  int temp = pq.top();
  if(pq.size() > 1){
    pq.pop();
    dia = max(dia, pq.top() + temp + 2);
  }
  if(pq.size() > 0){
    dia = max(dia, temp + 1);
    return temp + 1;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
  cin >> n >> k;
  
  int u, v;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  if(k == 1){
    vi isV(n+1, 0);
    func(1, isV);
    cout << (n-1)*2 - dia + 1;
  }
	return 0;
}