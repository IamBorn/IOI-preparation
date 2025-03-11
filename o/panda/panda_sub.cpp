#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
#include <set>
#include "panda.h"

using namespace std;

const int MAXN = 100005;
 
vector<vector<int>> adj;
vector<pair<int, int>> dist; //city, dist
 
class SegTree{
  private:
  int size;
  int t[4*MAXN+4];
 
  void SegTreeUtil(int v, int tl, int tr){
    if(tl==tr){
      t[v]=0;
    }
    else{
      int tm=(tl+tr)/2;
      SegTreeUtil(v*2,tl,tm);
      SegTreeUtil(v*2+1,tm+1,tr);
      t[v]=max(t[v*2],t[v*2+1]);
    }
  }
 
  int rangeUtil(int v, int tl, int tr, int l, int r){
    if(l > r) return -10000000;
    if(l==tl&&r==tr){
      return t[v];
    }
    int tm=(tl+tr)/2;
    return max(rangeUtil(v*2, tl, tm, l, min(r, tm))
           , rangeUtil(v*2+1, tm+1, tr, max(l, tm+1), r)
            );
  }
 
  void updateUtil(int v, int tl, int tr, int pos, int val){
    if(tl==tr){
      t[v]=val;
    }
    else{
      int tm=(tl+tr)/2;
      if(pos<=tm){
        updateUtil(v*2,tl,tm,pos,val);
      }
      else{
        updateUtil(v*2+1,tm+1,tr,pos,val);
      }
      t[v]=max(t[v*2],t[v*2+1]);
    }
  }
 
  public:
  SegTree(int n){
    size=n;
  }
 
  int range(int l, int r){
    return rangeUtil(1,0,size-1,l,r);
  }
 
  void update(int pos, int val){
    updateUtil(1,0,size-1,pos,val);
  }
}; 
 
vector<multiset<int, greater<int>>> E; // E, forest
multiset<int, greater<int>> EL_0[12];
multiset<int, greater<int>> ER_0[12];
 
SegTree* t;
vector<SegTree> left;
vector<SegTree> right;
 
int glo_S;
 
void initialize(int N,int M,int S,std::vector<std::vector<int> >R)
{
    glo_S = S;
    t = new SegTree(S+1);
    for(int i = 0; i <= 11; i++){
        left.push_back(*t);
        right.push_back(*t);
    }
    adj.resize(N+5);
    dist.resize(N+5);
    for(int i = 0; i < N; i++){
        dist[i] = {-1, 1000000};
    }
    E.resize(S+6);


    for(int i = S; i < M; i++){
        adj[R[i][0]].push_back(R[i][1]);
        adj[R[i][1]].push_back(R[i][0]);
    }
    vector<bool> isV(N, false);
    for(int i = 0; i <= S; i++){
        queue<pair<int, int>> st;
        st.push({i, 0});
        isV[i] = true;
        while(!st.empty()){
            auto now = st.front();
            st.pop();

            if(now.second >= dist[now.first].second) continue;
            for(auto v : adj[now.first]){
                if(isV[v]) continue;
                dist[v].second = now.second + 1;
                dist[v].first = i;
                isV[v] = true;
                st.push({v, dist[v].second});
            }
        }
    }
}
 
void panda_spawn(int P,int L,int X)
{
    int city = dist[X].first;
    int val = P - L*dist[X].second;
 
    E[city].insert(val);
    EL_0[L].insert(val - L*(glo_S - city));
    ER_0[L].insert(val- L*(city));
 
    t->update(city, val);
    left[L].update(city, *EL_0[L].begin());
    right[L].update(city, *ER_0[L].begin());
}
 
void panda_evac(int P,int L,int X)
{
    int city = dist[X].first;
    int val = P - (L*dist[X].second);
    E[city].erase(E[city].find(val));
    EL_0[L].erase(EL_0[L].find(val - L*(glo_S - city)));
    ER_0[L].erase(ER_0[L].find(val - L*(city)));
 
    auto now = E[city].begin();
    int now_n = *now;
    t->update(city, now_n);
    left[L].update(city, *EL_0[L].begin());
    right[L].update(city, *ER_0[L].begin());
}
 
int travel(int A,int B)
{
    if(A > B) swap(A, B);
 
    int ans = -10000000;
    for(int i = 1; i <= 10; i++){
        ans = max(ans, left[i].range(0, A) + i*(glo_S-A));
        ans = max(ans, right[i].range(B, glo_S) + i*(B));
    }
    int temp = t->range(A, B);
    if(temp == -10000000) temp = 0;
    if(ans == -10000000) ans = 0;
    return max(temp, ans);
}