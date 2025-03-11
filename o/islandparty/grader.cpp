#include "islandparty.h"
#include <vector>
#include <bits/stdc++.h>
#include <stack>
#include <cassert>
#include <cstdio>

using namespace std;

vector<long long> node;

/*const int MAXN = 100005;

struct FenwickTree{
    vector<long long> bit;


    FenwickTree(int n){
        bit.assign(n, 0);
    }

    FenwickTree(vector<long long> A){

    }

    void add()
};*/

void init(int N, int T, std::vector<long long> A, std::vector<int> u, std::vector<int> v) {
    node.resize(N);
    stack<int> s;
    vector<vector<int>> adj(N);
    vector<bool> isV(N, false);
    for(int i = 0; i < N-1; i++){
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
    s.push(0);
    node[0] = A[0];
    isV[0] = true;

    while(!s.empty()){
        int now = s.top(); s.pop();

        for(auto i : adj[now]){
            if(isV[i]) continue;

            node[i] = node[now] ^ A[i];
            s.push(i);
            isV[i] = true;
        }
    }

    for(int i = 1; i < N; i++){
        node[i] ^= node[i-1];
    }
    return;
}

long long find_drunkenness(int L, int R, int X) {
    int temp1, temp2;
    if(L == 0){
        temp1 = node[R];
    }
    else{
        temp1 = node[R] ^ node[L-1];
    }

    if(X == 0){
        temp2 = node[X];
    }
    else{
        temp2 = node[X] ^ node[X-1];
    }
    cout << temp1 << " " << temp2 << "\n";

    return temp1 ^ temp2;
}

int main() {
    int N, T;
    assert(scanf(" %d %d", &N, &T) == 2);
    std::vector<long long> A(N);
    std::vector<int> u(N - 1), v(N - 1), L(T), R(T), X(T);
    for (int i = 0; i < N; i++) {
        assert(scanf(" %lld", &A[i]) == 1);
    }
    for (int i = 0; i < N - 1; i++) {
        assert(scanf(" %d %d", &u[i], &v[i]) == 2);
    }

    init(N, T, A, u, v);

    for (int i = 0; i < T; i++) {
        assert(scanf(" %d %d %d", &L[i], &R[i], &X[i]) == 3);

        printf("%lld\n", find_drunkenness(L[i], R[i], X[i]));
    }
    return 0;
}
