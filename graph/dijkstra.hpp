#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int to, cost;
};

// 1LL << 60 if infty
vector<long long> dijkstra(vector<vector<Edge>> g, int s) {
    vector<long long> ret((int) g.size(), 1LL << 60);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push({0, s});
    ret[s] = 0;
    while (!q.empty()) {
        pair<long long, int> p = q.top(); q.pop();
        long long &dist = p.first;
        int &v = p.second;
        if (ret[v] < dist) continue;
        ret[v] = dist;
        for (Edge &e : g[v]) {
            if (ret[e.to] > dist + e.cost) {
                ret[e.to] = dist + e.cost;
                q.push({dist + e.cost, e.to});
            }
        }
    }
    return ret;
}
