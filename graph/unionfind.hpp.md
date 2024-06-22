---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unionfind.test.cpp
    title: test/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/unionfind.hpp\"\n#include <vector>\n#include <utility>\n\
    #include <cassert>\n\nstruct UnionFind {\n    private:\n    int n;\n    std::vector<int>\
    \ par, rank, size_mem;\n\n    public:\n    UnionFind(int _n) : n(_n), par(_n,\
    \ -1), rank(_n, 0), size_mem(_n, 1) {}\n\n    int root(int x) {\n        assert(0\
    \ <= x && x < n);\n\n        if (par[x] == -1) return x;\n        else return\
    \ par[x] = root(par[x]);\n    }\n\n    bool same(int x, int y) {\n        assert(0\
    \ <= x && x < n);\n        assert(0 <= y && y < n);\n\n        return root(x)\
    \ == root(y);\n    }\n\n    bool unite(int x, int y) {\n        assert(0 <= x\
    \ && x < n);\n        assert(0 <= y && y < n);\n\n        int rx = root(x), ry\
    \ = root(y);\n        if (rx == ry) return false;\n\n        // ry \u306E\u307B\
    \u3046\u304C\u5C0F\u3055\u3044\u3088\u3046\u306B\u3059\u308B\n        if (rank[rx]\
    \ < rank[ry]) std::swap(rx, ry);\n\n        // ry \u304C rx \u306E\u5B50\u3068\
    \u3059\u308B\n        par[ry] = rx;\n        if (rank[rx] == rank[ry]) rank[rx]++;\n\
    \        size_mem[rx] += size_mem[ry];\n\n        return true;\n    }\n\n    int\
    \ size(int x) {\n        assert(0 <= x && x < n);\n        return size_mem[root(x)];\n\
    \    }\n\n    std::vector<std::vector<int>> groups() {\n        std::vector<std::vector<int>>\
    \ tmp(n);\n        for (int i = 0; i < n; i++) {\n            tmp[root(i)].push_back(i);\n\
    \        }\n        std::vector<std::vector<int>> ret;\n        for (int i = 0;\
    \ i < n; i++) {\n            if (!tmp[i].empty()) {\n                ret.push_back(tmp[i]);\n\
    \            }\n        }\n        return ret;\n    }\n};\n\nstruct UnionFind2D\
    \ {\n    private:\n    int h, w;\n    UnionFind uf;\n    \n    public:\n    UnionFind2D(int\
    \ _h, int _w) : h(_h), w(_w), uf(_h * _w) {}\n\n    std::pair<int, int> root(int\
    \ i, int j) {\n        int tmp = uf.root(i * w + j);\n        return std::make_pair(tmp\
    \ / w, tmp % w);\n    }\n\n    bool same(int i1, int j1, int i2, int j2) {\n \
    \       return uf.same(i1 * w + j1, i2 * w + j2);\n    }\n\n    bool unite(int\
    \ i1, int j1, int i2, int j2) {\n        return uf.unite(i1 * w + j1, i2 * w +\
    \ j2);\n    }\n\n    int size(int i, int j) {\n        return uf.size(i * w +\
    \ j);\n    }\n\n    std::vector<std::vector<std::pair<int, int>>> groups() {\n\
    \        std::vector<std::vector<std::pair<int, int>>> tmp(h * w);\n        for\
    \ (int i = 0; i < h; i++) {\n            for (int j = 0; j < w; j++) {\n     \
    \           std::pair<int, int> r = root(i, j);\n                tmp[r.first *\
    \ w + r.second].emplace_back(i, j);\n            }\n        }\n        std::vector<std::vector<std::pair<int,\
    \ int>>> ret;\n        for (int i = 0; i < h * w; i++) {\n            if (!tmp[i].empty())\
    \ {\n                ret.push_back(tmp[i]);\n            }\n        }\n      \
    \  return ret;\n    }\n};\n"
  code: "#include <vector>\n#include <utility>\n#include <cassert>\n\nstruct UnionFind\
    \ {\n    private:\n    int n;\n    std::vector<int> par, rank, size_mem;\n\n \
    \   public:\n    UnionFind(int _n) : n(_n), par(_n, -1), rank(_n, 0), size_mem(_n,\
    \ 1) {}\n\n    int root(int x) {\n        assert(0 <= x && x < n);\n\n       \
    \ if (par[x] == -1) return x;\n        else return par[x] = root(par[x]);\n  \
    \  }\n\n    bool same(int x, int y) {\n        assert(0 <= x && x < n);\n    \
    \    assert(0 <= y && y < n);\n\n        return root(x) == root(y);\n    }\n\n\
    \    bool unite(int x, int y) {\n        assert(0 <= x && x < n);\n        assert(0\
    \ <= y && y < n);\n\n        int rx = root(x), ry = root(y);\n        if (rx ==\
    \ ry) return false;\n\n        // ry \u306E\u307B\u3046\u304C\u5C0F\u3055\u3044\
    \u3088\u3046\u306B\u3059\u308B\n        if (rank[rx] < rank[ry]) std::swap(rx,\
    \ ry);\n\n        // ry \u304C rx \u306E\u5B50\u3068\u3059\u308B\n        par[ry]\
    \ = rx;\n        if (rank[rx] == rank[ry]) rank[rx]++;\n        size_mem[rx] +=\
    \ size_mem[ry];\n\n        return true;\n    }\n\n    int size(int x) {\n    \
    \    assert(0 <= x && x < n);\n        return size_mem[root(x)];\n    }\n\n  \
    \  std::vector<std::vector<int>> groups() {\n        std::vector<std::vector<int>>\
    \ tmp(n);\n        for (int i = 0; i < n; i++) {\n            tmp[root(i)].push_back(i);\n\
    \        }\n        std::vector<std::vector<int>> ret;\n        for (int i = 0;\
    \ i < n; i++) {\n            if (!tmp[i].empty()) {\n                ret.push_back(tmp[i]);\n\
    \            }\n        }\n        return ret;\n    }\n};\n\nstruct UnionFind2D\
    \ {\n    private:\n    int h, w;\n    UnionFind uf;\n    \n    public:\n    UnionFind2D(int\
    \ _h, int _w) : h(_h), w(_w), uf(_h * _w) {}\n\n    std::pair<int, int> root(int\
    \ i, int j) {\n        int tmp = uf.root(i * w + j);\n        return std::make_pair(tmp\
    \ / w, tmp % w);\n    }\n\n    bool same(int i1, int j1, int i2, int j2) {\n \
    \       return uf.same(i1 * w + j1, i2 * w + j2);\n    }\n\n    bool unite(int\
    \ i1, int j1, int i2, int j2) {\n        return uf.unite(i1 * w + j1, i2 * w +\
    \ j2);\n    }\n\n    int size(int i, int j) {\n        return uf.size(i * w +\
    \ j);\n    }\n\n    std::vector<std::vector<std::pair<int, int>>> groups() {\n\
    \        std::vector<std::vector<std::pair<int, int>>> tmp(h * w);\n        for\
    \ (int i = 0; i < h; i++) {\n            for (int j = 0; j < w; j++) {\n     \
    \           std::pair<int, int> r = root(i, j);\n                tmp[r.first *\
    \ w + r.second].emplace_back(i, j);\n            }\n        }\n        std::vector<std::vector<std::pair<int,\
    \ int>>> ret;\n        for (int i = 0; i < h * w; i++) {\n            if (!tmp[i].empty())\
    \ {\n                ret.push_back(tmp[i]);\n            }\n        }\n      \
    \  return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/unionfind.hpp
  requiredBy: []
  timestamp: '2024-06-22 20:58:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unionfind.test.cpp
documentation_of: graph/unionfind.hpp
layout: document
redirect_from:
- /library/graph/unionfind.hpp
- /library/graph/unionfind.hpp.html
title: graph/unionfind.hpp
---
