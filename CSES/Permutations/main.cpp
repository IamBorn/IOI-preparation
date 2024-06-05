/*
	* AUTHOR : lo0ker
	* Problem : Permutations
	* source : https://cses.fi/problemset/task/1070
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

	int n;
  cin >> n;
  if(n == 1){
    cout << 1;
  }
  else if(n < 4){
    cout << "NO SOLUTION";
  }
  else{
    for(int i = 2; i <= n; i+= 2){
      cout << i << " ";
    }
    for(int i = 1; i <= n; i+= 2){
      cout << i << " ";
    }
  }
	return 0;
}