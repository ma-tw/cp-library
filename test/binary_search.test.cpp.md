---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algo/binary_search.hpp
    title: algo/binary_search.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/typical90/tasks/typical90_a
    links:
    - https://atcoder.jp/contests/typical90/tasks/typical90_a
  bundledCode: "#line 1 \"test/binary_search.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/typical90/tasks/typical90_a\"\
    \n#include <bits/stdc++.h>\n#line 2 \"algo/binary_search.hpp\"\n\n// binary search,\
    \ finds the border of determ\ntemplate <typename T = long long, typename U>\n\
    T find_border(T ok, T ng, const U determ) {\n    while (abs(ok - ng) > 1) {\n\
    \        T mid = (ok + ng) / 2;\n        if (determ(mid)) {\n            ok =\
    \ mid;\n        } else {\n            ng = mid;\n        }\n    }\n    return\
    \ ok;\n}\n#line 4 \"test/binary_search.test.cpp\"\nusing namespace std;\n\nint\
    \ main() {\n    int n, l, k;\n    cin >> n >> l >> k;\n    vector<int> a(n);\n\
    \    for (int i = 0; i < n; i++) cin >> a[i];\n    cout << find_border<int>(0,\
    \ 1e9, [&](int x) {\n        int cnt = 0;\n        int last = 0;\n        for\
    \ (int i = 0; i < n; i++) {\n            if (a[i] - last >= x) {\n           \
    \     cnt++;\n                last = a[i];\n            }\n        }\n       \
    \ cnt += l - last >= x;\n        return cnt >= k + 1;\n    }) << endl;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/typical90/tasks/typical90_a\"\
    \n#include <bits/stdc++.h>\n#include \"../algo/binary_search.hpp\"\nusing namespace\
    \ std;\n\nint main() {\n    int n, l, k;\n    cin >> n >> l >> k;\n    vector<int>\
    \ a(n);\n    for (int i = 0; i < n; i++) cin >> a[i];\n    cout << find_border<int>(0,\
    \ 1e9, [&](int x) {\n        int cnt = 0;\n        int last = 0;\n        for\
    \ (int i = 0; i < n; i++) {\n            if (a[i] - last >= x) {\n           \
    \     cnt++;\n                last = a[i];\n            }\n        }\n       \
    \ cnt += l - last >= x;\n        return cnt >= k + 1;\n    }) << endl;\n}"
  dependsOn:
  - algo/binary_search.hpp
  isVerificationFile: true
  path: test/binary_search.test.cpp
  requiredBy: []
  timestamp: '2024-06-14 18:05:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/binary_search.test.cpp
layout: document
redirect_from:
- /verify/test/binary_search.test.cpp
- /verify/test/binary_search.test.cpp.html
title: test/binary_search.test.cpp
---
