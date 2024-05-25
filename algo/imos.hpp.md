---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algo/cuml_sum.hpp
    title: algo/cuml_sum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algo/imos.hpp\"\n#include <vector>\nusing namespace std;\n\
    \n#line 2 \"algo/cuml_sum.hpp\"\nusing namespace std;\n\ntemplate<typename T =\
    \ long long>\nstruct CumlSum {\n    CumlSum(size_t n) : _s(n + 1), _a(n), ready(false)\
    \ {}\n    CumlSum(vector<T> a) : _s(a.size() + 1), _a(a), ready(false) {}\n  \
    \  void assign(unsigned int p, T x) {\n        if (_a[p] != x) ready = false;\n\
    \        _a[p] = x;\n    }\n\n    // [l, r)\n    // O(n * (calls after changes))\n\
    \    T sum(unsigned int l, unsigned int r) {\n        if (!ready) {\n        \
    \    for (int i = 0; i < (int) _s.size() - 1; i++) {\n                _s[i + 1]\
    \ = _s[i] + _a[i];\n            }\n            ready = true;\n        }\n    \
    \    return _s[r] - _s[l];\n    }\n    private:\n    vector<T> _s, _a;\n    bool\
    \ ready;\n};\n#line 5 \"algo/imos.hpp\"\ntemplate<typename T = long long>\nstruct\
    \ Imos {\n    Imos(size_t n) : _cs(n) {}\n\n    // [l, r)\n    void add(unsigned\
    \ int l, unsigned int r, int value) {\n        _cs.assign(l, value);\n       \
    \ _cs.assign(r, -value);\n    }\n\n    T get(unsigned int p) {\n        return\
    \ _cs.sum(p, p + 1);\n    }\n    private:\n    CumlSum<T> _cs;\n};\n"
  code: "#include <vector>\nusing namespace std;\n\n#include \"cuml_sum.hpp\"\ntemplate<typename\
    \ T = long long>\nstruct Imos {\n    Imos(size_t n) : _cs(n) {}\n\n    // [l,\
    \ r)\n    void add(unsigned int l, unsigned int r, int value) {\n        _cs.assign(l,\
    \ value);\n        _cs.assign(r, -value);\n    }\n\n    T get(unsigned int p)\
    \ {\n        return _cs.sum(p, p + 1);\n    }\n    private:\n    CumlSum<T> _cs;\n\
    };\n"
  dependsOn:
  - algo/cuml_sum.hpp
  isVerificationFile: false
  path: algo/imos.hpp
  requiredBy: []
  timestamp: '2024-05-04 20:54:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algo/imos.hpp
layout: document
redirect_from:
- /library/algo/imos.hpp
- /library/algo/imos.hpp.html
title: algo/imos.hpp
---
