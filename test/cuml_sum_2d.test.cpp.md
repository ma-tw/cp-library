---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algo/cuml_sum_2d.hpp
    title: algo/cuml_sum_2d.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560
  bundledCode: "#line 1 \"test/cuml_sum_2d.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560\"\
    \n\n#include <bits/stdc++.h>\n#line 2 \"algo/cuml_sum_2d.hpp\"\nusing namespace\
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
    };\n#line 5 \"test/cuml_sum_2d.test.cpp\"\nusing namespace std;\n\nint main()\
    \ {\n    int h, w, q;\n    cin >> h >> w >> q;\n    vector<string> a(h);\n   \
    \ for (int i = 0; i < h; i++) cin >> a[i];\n    CumlSum2D sj(h, w), si(h, w),\
    \ so(h, w);\n    for (int i = 0; i < h; i++) {\n        for (int j = 0; j < w;\
    \ j++) {\n            sj.assign(i, j, a[i][j] == 'J');\n            si.assign(i,\
    \ j, a[i][j] == 'I');\n            so.assign(i, j, a[i][j] == 'O');\n        }\n\
    \    }\n    while (q--) {\n        int a, b, c, d;\n        cin >> a >> b >> c\
    \ >> d;\n        a--, b--;\n        cout << sj.sum(a, b, c, d) << ' ' << so.sum(a,\
    \ b, c, d) << ' ' << si.sum(a, b, c, d) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560\"\
    \n\n#include <bits/stdc++.h>\n#include \"../algo/cuml_sum_2d.hpp\"\nusing namespace\
    \ std;\n\nint main() {\n    int h, w, q;\n    cin >> h >> w >> q;\n    vector<string>\
    \ a(h);\n    for (int i = 0; i < h; i++) cin >> a[i];\n    CumlSum2D sj(h, w),\
    \ si(h, w), so(h, w);\n    for (int i = 0; i < h; i++) {\n        for (int j =\
    \ 0; j < w; j++) {\n            sj.assign(i, j, a[i][j] == 'J');\n           \
    \ si.assign(i, j, a[i][j] == 'I');\n            so.assign(i, j, a[i][j] == 'O');\n\
    \        }\n    }\n    while (q--) {\n        int a, b, c, d;\n        cin >>\
    \ a >> b >> c >> d;\n        a--, b--;\n        cout << sj.sum(a, b, c, d) <<\
    \ ' ' << so.sum(a, b, c, d) << ' ' << si.sum(a, b, c, d) << endl;\n    }\n}"
  dependsOn:
  - algo/cuml_sum_2d.hpp
  isVerificationFile: true
  path: test/cuml_sum_2d.test.cpp
  requiredBy: []
  timestamp: '2024-05-04 20:54:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cuml_sum_2d.test.cpp
layout: document
redirect_from:
- /verify/test/cuml_sum_2d.test.cpp
- /verify/test/cuml_sum_2d.test.cpp.html
title: test/cuml_sum_2d.test.cpp
---
