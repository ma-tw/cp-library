#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include <bits/stdc++.h>
#include "../graph/dijkstra.hpp"
using namespace std;

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<Edge>> g(n), inv(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        inv[b].emplace_back(a, c);
    }
    vector<long long> dist = dijkstra(g, s);
    if (dist[t] == 1LL << 60) cout << -1 << endl;
    else {
        vector<pair<int, int>> ans;
        int x = t;
        while (x != s) {
            for (auto e : inv[x]) {
                if (dist[e.to] == dist[x] - e.cost) {
                    ans.emplace_back(e.to, x);
                    x = e.to;
                    break;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        cout << dist[t] << ' ' << ans.size() << endl;
        for (auto [u, v] : ans) {
            cout << u << ' ' << v << endl;
        }
    }
}