/*
	* AUTHOR : lo0ker
	* Problem : Sound
	* source : https://dmoj.ca/problem/btoi07p3
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

	int n, m, c;
  cin >> n >> m >> c;
  vi a(n);
  for(auto &it : a) cin >> it;

  multiset<int> ms;
  for(int i = 0; i < m-1; i++){
    ms.insert(a[i]);
  }
  int cnt = 0;
  for(int i = m-1; i < n; i++){
    ms.insert(a[i]);
    auto b = ms.begin();
    auto e = ms.end();
    e--;
    if(*e - *b <= c){
      cout << i-m+2 << "\n";
      cnt++;
    }

    ms.erase(ms.find(a[i-m+1]));
  }
  if(cnt == 0){
    cout << "NONE\n";
  }
	return 0;
}