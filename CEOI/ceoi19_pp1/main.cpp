/*
	* AUTHOR : lo0ker
	* Problem : Count Squares
	* source : https://dmoj.ca/problem/ceoi19pp1
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

	int h, v;
	cin >> h >> v;
	vector<ll> y(h);
	for(auto &it : y) cin >> it;
	vector<ll> x(v);
	for(auto &it : x) cin >> it;

	ll ans = 0;
	map<ll, int> ma;
	for(int i = 0; i < h; i++){
		for(int j = i+1; j < h; j++){
			ma[y[j] - y[i]]++;
		}
	}

	for(int i = 0; i < v; i++){
		for(int j = i+1; j < v; j++){
			ans += ma[x[j] - x[i]];
		}
	}

	cout << ans;
	return 0;
}