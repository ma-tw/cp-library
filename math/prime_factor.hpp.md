---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/prime_factor.test.cpp
    title: test/prime_factor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/prime_factor.hpp\"\n#include <map>\nusing namespace\
    \ std;\n\nmap<long long, int> prime_factor(long long n) {\n    map<long long,\
    \ int> ret;\n    for (long long i = 2; i * i <= n; i++) {\n        while (n %\
    \ i == 0) {\n            ret[i]++;\n            n /= i;\n        }\n    }\n  \
    \  if (n != 1) ret[n] = 1;\n    return ret;\n}\n"
  code: "#include <map>\nusing namespace std;\n\nmap<long long, int> prime_factor(long\
    \ long n) {\n    map<long long, int> ret;\n    for (long long i = 2; i * i <=\
    \ n; i++) {\n        while (n % i == 0) {\n            ret[i]++;\n           \
    \ n /= i;\n        }\n    }\n    if (n != 1) ret[n] = 1;\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_factor.hpp
  requiredBy: []
  timestamp: '2024-04-20 20:43:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/prime_factor.test.cpp
documentation_of: math/prime_factor.hpp
layout: document
redirect_from:
- /library/math/prime_factor.hpp
- /library/math/prime_factor.hpp.html
title: math/prime_factor.hpp
---
