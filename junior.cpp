/*
 * Hello Junior Dev!
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=1e9+7;

ll pow(ll base, ll exp){
  if(exp==0){return 1ll;}
  if(exp==1){return base;}
  ll ret=pow(base,exp/2);
  if(exp%2==0){return (ret*ret)%MOD;}
  return (((ret*ret)%MOD)*base)%MOD;
}

ll H(ll key, ll idx){
  return (pow((key+idx),idx)+key*idx)%10;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);\
  string answer[10]={"A2","C1","B2","C2","B1","C3","A1","D1","B3","D2"};
  const ll key=1573;

  ll new_sequence[10];

  for(int i=0;i<10;i++){
    swap(answer[i],answer[H(key,i)]);
  }
  for(int i=0;i<10;i++){
    cout << answer[i] << " ";
  }
  return 0;
}