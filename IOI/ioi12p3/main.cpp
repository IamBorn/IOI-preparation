/*
	* AUTHOR : lo0ker
	* Problem : 
	* source : 
*/

#include <bits/stdc++.h>
#include "lib.h"

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

	Init();
  TypeLetter('a');
  TypeLetter('b');
  cout <<  GetLetter(1) << "\n";
  TypeLetter('d');
  UndoCommands(2);
  UndoCommands(1);
  cout << GetLetter(2) << "\n";
	return 0;
}