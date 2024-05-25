---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algo/imos.hpp
    title: algo/imos.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cuml_sum.test.cpp
    title: test/cuml_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algo/cuml_sum.hpp\"\n#include <vector>\nusing namespace\
    \ std;\n\ntemplate<typename T = long long>\nstruct CumlSum {\n    CumlSum(size_t\
    \ n) : _s(n + 1), _a(n), ready(false) {}\n    CumlSum(vector<T> a) : _s(a.size()\
    \ + 1), _a(a), ready(false) {}\n    void assign(unsigned int p, T x) {\n     \
    \   if (_a[p] != x) ready = false;\n        _a[p] = x;\n    }\n\n    // [l, r)\n\
    \    // O(n * (calls after changes))\n    T sum(unsigned int l, unsigned int r)\
    \ {\n        if (!ready) {\n            for (int i = 0; i < (int) _s.size() -\
    \ 1; i++) {\n                _s[i + 1] = _s[i] + _a[i];\n            }\n     \
    \       ready = true;\n        }\n        return _s[r] - _s[l];\n    }\n    private:\n\
    \    vector<T> _s, _a;\n    bool ready;\n};\n"
  code: "#include <vector>\nusing namespace std;\n\ntemplate<typename T = long long>\n\
    struct CumlSum {\n    CumlSum(size_t n) : _s(n + 1), _a(n), ready(false) {}\n\
    \    CumlSum(vector<T> a) : _s(a.size() + 1), _a(a), ready(false) {}\n    void\
    \ assign(unsigned int p, T x) {\n        if (_a[p] != x) ready = false;\n    \
    \    _a[p] = x;\n    }\n\n    // [l, r)\n    // O(n * (calls after changes))\n\
    \    T sum(unsigned int l, unsigned int r) {\n        if (!ready) {\n        \
    \    for (int i = 0; i < (int) _s.size() - 1; i++) {\n                _s[i + 1]\
    \ = _s[i] + _a[i];\n            }\n            ready = true;\n        }\n    \
    \    return _s[r] - _s[l];\n    }\n    private:\n    vector<T> _s, _a;\n    bool\
    \ ready;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algo/cuml_sum.hpp
  requiredBy:
  - algo/imos.hpp
  timestamp: '2024-05-04 20:54:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cuml_sum.test.cpp
documentation_of: algo/cuml_sum.hpp
layout: document
redirect_from:
- /library/algo/cuml_sum.hpp
- /library/algo/cuml_sum.hpp.html
title: algo/cuml_sum.hpp
---
