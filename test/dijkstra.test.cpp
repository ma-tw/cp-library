#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"
#include <bits/stdc++.h>
#include "../graph/dijkstra.hpp"
using namespace std;

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<Edge>> g(n), inv(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        inv[b].push_back({a, c});
    }
    vector<long long> dist = dijkstra(g, r);
    for (int i = 0; i < n; i++) {
        if (dist[i] == 1LL << 60) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}