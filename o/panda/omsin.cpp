#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+5, MAXT = 4*MAXN + 5;

struct segtree{
    int pandacnt = 0;
    vector<tuple<int, int, int>> panda; // P, L, X
    map<tuple<int, int, int>, stack<int>> panda_map;
    vector<bool> is_deleted;
    priority_queue<pair<int, int>> tree[MAXT];
    vector<int> lazy[MAXT];

    void push(int u, int l, int r) {
        for (int i : lazy[u]) {
            if (is_deleted[i]) continue;
            int P, L, X;
            tie(P, L, X) = panda[i];
            if (l <= X && X <= r)
                tree[u].emplace(P, i);
            else
                tree[u].emplace(max(P - L*abs(X-l), P - L*abs(X-r)), i);

            if (l < r) {
                lazy[u<<1].push_back(i);
                lazy[(u<<1)+1].push_back(i);
            }
        }

        lazy[u].clear();
        while (!tree[u].empty() && is_deleted[tree[u].top().second]) tree[u].pop();
    }
    
    void spawn(int P, int L, int X) {
        panda.emplace_back(P, L, X);
        is_deleted.push_back(false);
        panda_map[make_tuple(P, L, X)].push(pandacnt);
        lazy[1].push_back(pandacnt);
        pandacnt++;
    }

    void evac(int P, int L, int X) {
        int idx = panda_map[make_tuple(P, L, X)].top();
        panda_map[make_tuple(P, L, X)].pop();
        is_deleted[idx] = true;
    }

    int query(int l, int r, int tl = 0, int tr = MAXN, int v = 1) {
        push(v, tl, tr);
        if (l <= tl && tr <= r) {
            if (tree[v].empty()) return INT_MIN;
            return tree[v].top().first;
        }
        if (tr < l || r < tl) return INT_MIN;

        int mid = (tl+tr)>>1;
        return max(query(l, r, tl, mid, v<<1), query(l, r, mid+1, tr, (v<<1)+1));
    } 
} segt;

int src[MAXN], dist[MAXN];
void initialize(int N, int M, int S, vector<vector<int>> R) {
    vector<int> edge[N];
    for (vector<int> e : R) {
        edge[e[0]].push_back(e[1]);
        edge[e[1]].push_back(e[0]);
    }

    queue<int> bfs_q;
    bool visited[N];
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i <= S; i++) {
        src[i] = i;
        dist[i] = 0;
        bfs_q.push(i);
    }

    for (int i = S+1; i < N; i++) {
        src[i] = -1;
        dist[i] = INT_MAX;
    }

    while (!bfs_q.empty()) {
        int u = bfs_q.front();
        bfs_q.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (int v : edge[u]) {
            if (dist[v] > dist[u] + 1) {
                src[v] = src[u];
                dist[v] = dist[u] + 1;
                bfs_q.push(v);
            }
        }
    }
}

void panda_spawn(int P, int L, int X) {
    P -= L*dist[X];
    segt.spawn(P, L, src[X]);
}

void panda_evac(int P, int L, int X) {
    P -= L*dist[X];
    segt.evac(P, L, src[X]);
}

int travel(int A, int B) {
    if (A > B) swap(A, B);
    return segt.query(A, B);
}