/*
	* AUTHOR : lo0ker
	* Problem : detect virus
	* source : 
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

bool func(vector<int> v){
  int n = sz(v);
  if(n == 2) return true;
  vector<int> v1;
  vector<int> v2;
  int cnt = 0;
  for(int i = 0; i < n/2; i++){
    if(v[i] == 1) cnt++;
    if(v[i + n/2]) cnt--;

    v1.push_back(v[i]);
    v2.push_back(v[i + n/2]);
  }

  if(abs(cnt) > 1) return false;

  return (func(v1) && func(v2));
}

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    vector<int> v;
    int a;
    for(int j = 0; j < pow(2, k); j++){
      cin >> a;
      v.push_back(a);
    }

    if(func(v)) cout << "yes";
    else cout << "no";
    cout << '\n';
  }
	return 0;
}