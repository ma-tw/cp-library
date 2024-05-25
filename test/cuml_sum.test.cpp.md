---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algo/cuml_sum.hpp
    title: algo/cuml_sum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/cuml_sum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
    \n#include <bits/stdc++.h>\n#line 2 \"algo/cuml_sum.hpp\"\nusing namespace std;\n\
    \ntemplate<typename T = long long>\nstruct CumlSum {\n    CumlSum(size_t n) :\
    \ _s(n + 1), _a(n), ready(false) {}\n    CumlSum(vector<T> a) : _s(a.size() +\
    \ 1), _a(a), ready(false) {}\n    void assign(unsigned int p, T x) {\n       \
    \ if (_a[p] != x) ready = false;\n        _a[p] = x;\n    }\n\n    // [l, r)\n\
    \    // O(n * (calls after changes))\n    T sum(unsigned int l, unsigned int r)\
    \ {\n        if (!ready) {\n            for (int i = 0; i < (int) _s.size() -\
    \ 1; i++) {\n                _s[i + 1] = _s[i] + _a[i];\n            }\n     \
    \       ready = true;\n        }\n        return _s[r] - _s[l];\n    }\n    private:\n\
    \    vector<T> _s, _a;\n    bool ready;\n};\n#line 4 \"test/cuml_sum.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n  \
    \  CumlSum s(n);\n    for (int i = 0; i < n; i++) {\n        int x;\n        cin\
    \ >> x;\n        s.assign(i, x);\n    }\n    while (q--) {\n        int l, r;\n\
    \        cin >> l >> r;\n        cout << s.sum(l, r) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <bits/stdc++.h>\n#include \"../algo/cuml_sum.hpp\"\nusing namespace std;\n\n\
    int main() {\n    int n, q;\n    cin >> n >> q;\n    CumlSum s(n);\n    for (int\
    \ i = 0; i < n; i++) {\n        int x;\n        cin >> x;\n        s.assign(i,\
    \ x);\n    }\n    while (q--) {\n        int l, r;\n        cin >> l >> r;\n \
    \       cout << s.sum(l, r) << endl;\n    }\n}"
  dependsOn:
  - algo/cuml_sum.hpp
  isVerificationFile: true
  path: test/cuml_sum.test.cpp
  requiredBy: []
  timestamp: '2024-05-04 20:54:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cuml_sum.test.cpp
layout: document
redirect_from:
- /verify/test/cuml_sum.test.cpp
- /verify/test/cuml_sum.test.cpp.html
title: test/cuml_sum.test.cpp
---
