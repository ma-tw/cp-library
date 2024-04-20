---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dijkstra.test.cpp
    title: test/dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/dijkstra.hpp\"\n#include <vector>\n#include <queue>\n\
    using namespace std;\n\nstruct Edge {\n    int to, cost;\n};\n\n// 1LL << 60 if\
    \ infty\nvector<long long> dijkstra(vector<vector<Edge>> g, int s) {\n    vector<long\
    \ long> ret((int) g.size(), 1LL << 60);\n    priority_queue<pair<long long, int>,\
    \ vector<pair<long long, int>>, greater<pair<long long, int>>> q;\n    q.push({0,\
    \ s});\n    ret[s] = 0;\n    while (!q.empty()) {\n        pair<long long, int>\
    \ p = q.top(); q.pop();\n        long long &dist = p.first;\n        int &v =\
    \ p.second;\n        if (ret[v] < dist) continue;\n        ret[v] = dist;\n  \
    \      for (Edge &e : g[v]) {\n            if (ret[e.to] > dist + e.cost) {\n\
    \                ret[e.to] = dist + e.cost;\n                q.push({dist + e.cost,\
    \ e.to});\n            }\n        }\n    }\n    return ret;\n}\n"
  code: "#include <vector>\n#include <queue>\nusing namespace std;\n\nstruct Edge\
    \ {\n    int to, cost;\n};\n\n// 1LL << 60 if infty\nvector<long long> dijkstra(vector<vector<Edge>>\
    \ g, int s) {\n    vector<long long> ret((int) g.size(), 1LL << 60);\n    priority_queue<pair<long\
    \ long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;\n\
    \    q.push({0, s});\n    ret[s] = 0;\n    while (!q.empty()) {\n        pair<long\
    \ long, int> p = q.top(); q.pop();\n        long long &dist = p.first;\n     \
    \   int &v = p.second;\n        if (ret[v] < dist) continue;\n        ret[v] =\
    \ dist;\n        for (Edge &e : g[v]) {\n            if (ret[e.to] > dist + e.cost)\
    \ {\n                ret[e.to] = dist + e.cost;\n                q.push({dist\
    \ + e.cost, e.to});\n            }\n        }\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2024-04-20 19:00:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dijkstra.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: graph/dijkstra.hpp
---
