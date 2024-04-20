---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime_factor.hpp
    title: math/prime_factor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
  bundledCode: "#line 1 \"test/prime_factor.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 2 \"math/prime_factor.hpp\"\
    \nusing namespace std;\n\nmap<long long, int> prime_factor(long long n) {\n  \
    \  map<long long, int> ret;\n    for (long long i = 2; i * i <= n; i++) {\n  \
    \      while (n % i == 0) {\n            ret[i]++;\n            n /= i;\n    \
    \    }\n    }\n    if (n != 1) ret[n] = 1;\n    return ret;\n}\n#line 5 \"test/prime_factor.test.cpp\"\
    \n\nint main() {\n    long long n;\n    cin >> n;\n    auto pf = prime_factor(n);\n\
    \    cout << n << \":\";\n    for (auto [x, y] : pf) {\n        for (int i = 0;\
    \ i < y; i++) cout << \" \" << x;\n    }\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../math/prime_factor.hpp\"\
    \n\nint main() {\n    long long n;\n    cin >> n;\n    auto pf = prime_factor(n);\n\
    \    cout << n << \":\";\n    for (auto [x, y] : pf) {\n        for (int i = 0;\
    \ i < y; i++) cout << \" \" << x;\n    }\n    cout << endl;\n}"
  dependsOn:
  - math/prime_factor.hpp
  isVerificationFile: true
  path: test/prime_factor.test.cpp
  requiredBy: []
  timestamp: '2024-04-20 20:43:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/prime_factor.test.cpp
layout: document
redirect_from:
- /verify/test/prime_factor.test.cpp
- /verify/test/prime_factor.test.cpp.html
title: test/prime_factor.test.cpp
---
