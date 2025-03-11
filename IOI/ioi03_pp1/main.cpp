/*
	* AUTHOR : lo0ker
	* Problem : Balancing Act
	* source : https://dmoj.ca/problem/ioi03pp1
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

vi adj[20005];
vi par;

void solve(int i){
  
}

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
  cin >> n;
  int a, b;
  par.assign(n+1, -1);
  for(int i = 0; i < n-1; i++){
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
	return 0;
}