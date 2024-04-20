---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"test/dijkstra.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n#include <bits/stdc++.h>\n#line 3 \"graph/dijkstra.hpp\"\nusing namespace std;\n\
    \nstruct Edge {\n    int to, cost;\n};\n\n// 1LL << 60 if infty\nvector<long long>\
    \ dijkstra(vector<vector<Edge>> g, int s) {\n    vector<long long> ret((int) g.size(),\
    \ 1LL << 60);\n    priority_queue<pair<long long, int>, vector<pair<long long,\
    \ int>>, greater<pair<long long, int>>> q;\n    q.push({0, s});\n    ret[s] =\
    \ 0;\n    while (!q.empty()) {\n        pair<long long, int> p = q.top(); q.pop();\n\
    \        long long &dist = p.first;\n        int &v = p.second;\n        if (ret[v]\
    \ < dist) continue;\n        ret[v] = dist;\n        for (Edge &e : g[v]) {\n\
    \            if (ret[e.to] > dist + e.cost) {\n                ret[e.to] = dist\
    \ + e.cost;\n                q.push({dist + e.cost, e.to});\n            }\n \
    \       }\n    }\n    return ret;\n}\n#line 4 \"test/dijkstra.test.cpp\"\nusing\
    \ namespace std;\n\nint main() {\n    int n, m, r;\n    cin >> n >> m >> r;\n\
    \    vector<vector<Edge>> g(n), inv(n);\n    for (int i = 0; i < m; i++) {\n \
    \       int a, b, c;\n        cin >> a >> b >> c;\n        g[a].push_back({b,\
    \ c});\n        inv[b].push_back({a, c});\n    }\n    vector<long long> dist =\
    \ dijkstra(g, r);\n    for (int i = 0; i < n; i++) {\n        if (dist[i] == 1LL\
    \ << 60) cout << \"INF\" << endl;\n        else cout << dist[i] << endl;\n   \
    \ }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n#include <bits/stdc++.h>\n#include \"../graph/dijkstra.hpp\"\nusing namespace\
    \ std;\n\nint main() {\n    int n, m, r;\n    cin >> n >> m >> r;\n    vector<vector<Edge>>\
    \ g(n), inv(n);\n    for (int i = 0; i < m; i++) {\n        int a, b, c;\n   \
    \     cin >> a >> b >> c;\n        g[a].push_back({b, c});\n        inv[b].push_back({a,\
    \ c});\n    }\n    vector<long long> dist = dijkstra(g, r);\n    for (int i =\
    \ 0; i < n; i++) {\n        if (dist[i] == 1LL << 60) cout << \"INF\" << endl;\n\
    \        else cout << dist[i] << endl;\n    }\n}"
  dependsOn:
  - graph/dijkstra.hpp
  isVerificationFile: true
  path: test/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2024-04-20 19:36:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/test/dijkstra.test.cpp
- /verify/test/dijkstra.test.cpp.html
title: test/dijkstra.test.cpp
---
