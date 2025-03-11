#include "cyberland.h"

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, long long>> adj[100005];

struct cur_node{
    long long dist;
    int cur, k;
};

vector<long long> dist[35];

double solve(int N, int M, int K, int H, std::vector<int> x, std::vector<int> y, std::vector<int> c, std::vector<int> arr) {
    priority_queue<cur_node> q;
    for(int i = 0; i < 35; i++){
        dist[i].assign(N, INT_MAX);
    }
    for(int i = 0; i < M; i++){
        adj[x[i]].push_back({y[i], c[i]});
        adj[y[i]].push_back({x[i], c[i]});
    }

    q.push({0, 0, 0});
    dist[0][0] = 0;

    while(!q.empty()){
        auto [d, i, cur_k] = q.top();
        q.pop();

        for(auto [j, cj] : adj[i]){
            if(d + cj < dist[j][cur_k]){
                dist[j][cur_k] = d + cj;
                q.push({d + cj, j, cur_k});
            }
            if(cur_k < K){
                if(arr[j] == 0){
                    dist[j][cur_k+1] = 0;
                    q.push({0, j, cur_k+1});
                }
                else if(arr[j] == 2){
                    
                }
            }
        }
    }
    return -1;
}