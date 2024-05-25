---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cuml_sum_2d.test.cpp
    title: test/cuml_sum_2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algo/cuml_sum_2d.hpp\"\n#include <vector>\nusing namespace\
    \ std;\n\ntemplate<typename T = long long>\nstruct CumlSum2D {\n    CumlSum2D(size_t\
    \ h, size_t w) : _h(h), _w(w), _s(h + 1, vector<T>(w + 1)), _a(h, vector<T>(w)),\
    \ ready(false) {}\n    CumlSum2D(vector<vector<T>> a) : _h(a.size()), _w(a.empty()\
    \ ? 0 : a[0].size()), _s(_h, vector<T>(_w)), _a(a), ready(false) {}\n    void\
    \ assign(unsigned int i, unsigned int j, T x) {\n        if (_a[i][j] != x) ready\
    \ = false;\n        _a[i][j] = x;\n    }\n\n    // [row_low, row_high), [col_low,\
    \ col_high)\n    // O(hw * (calls after changes))\n    T sum(unsigned int row_low,\
    \ unsigned int col_low, unsigned int row_high, unsigned int col_high) {\n    \
    \    if (!ready) {\n            for (int i = 0; i < _h; i++) {\n             \
    \   for (int j = 0; j < _w; j++) {\n                    _s[i + 1][j + 1] = _a[i][j];\n\
    \                }\n            }\n            for (int i = 0; i < _h; i++) {\n\
    \                for (int j = 0; j < _w; j++) {\n                    _s[i + 1][j\
    \ + 1] += _s[i][j + 1] + _s[i + 1][j] - _s[i][j];\n                }\n       \
    \     }\n            ready = true;\n        }\n        return _s[row_high][col_high]\
    \ + _s[row_low][col_low] - _s[row_high][col_low] - _s[row_low][col_high];\n  \
    \  }\n    private:\n    int _h, _w;\n    vector<vector<T>> _s, _a;\n    bool ready;\n\
    };\n"
  code: "#include <vector>\nusing namespace std;\n\ntemplate<typename T = long long>\n\
    struct CumlSum2D {\n    CumlSum2D(size_t h, size_t w) : _h(h), _w(w), _s(h + 1,\
    \ vector<T>(w + 1)), _a(h, vector<T>(w)), ready(false) {}\n    CumlSum2D(vector<vector<T>>\
    \ a) : _h(a.size()), _w(a.empty() ? 0 : a[0].size()), _s(_h, vector<T>(_w)), _a(a),\
    \ ready(false) {}\n    void assign(unsigned int i, unsigned int j, T x) {\n  \
    \      if (_a[i][j] != x) ready = false;\n        _a[i][j] = x;\n    }\n\n   \
    \ // [row_low, row_high), [col_low, col_high)\n    // O(hw * (calls after changes))\n\
    \    T sum(unsigned int row_low, unsigned int col_low, unsigned int row_high,\
    \ unsigned int col_high) {\n        if (!ready) {\n            for (int i = 0;\
    \ i < _h; i++) {\n                for (int j = 0; j < _w; j++) {\n           \
    \         _s[i + 1][j + 1] = _a[i][j];\n                }\n            }\n   \
    \         for (int i = 0; i < _h; i++) {\n                for (int j = 0; j <\
    \ _w; j++) {\n                    _s[i + 1][j + 1] += _s[i][j + 1] + _s[i + 1][j]\
    \ - _s[i][j];\n                }\n            }\n            ready = true;\n \
    \       }\n        return _s[row_high][col_high] + _s[row_low][col_low] - _s[row_high][col_low]\
    \ - _s[row_low][col_high];\n    }\n    private:\n    int _h, _w;\n    vector<vector<T>>\
    \ _s, _a;\n    bool ready;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algo/cuml_sum_2d.hpp
  requiredBy: []
  timestamp: '2024-05-04 20:54:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cuml_sum_2d.test.cpp
documentation_of: algo/cuml_sum_2d.hpp
layout: document
redirect_from:
- /library/algo/cuml_sum_2d.hpp
- /library/algo/cuml_sum_2d.hpp.html
title: algo/cuml_sum_2d.hpp
---
