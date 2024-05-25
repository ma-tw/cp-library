---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/binary_search.test.cpp
    title: test/binary_search.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algo/binary_search.hpp\"\n#include <functional>\n\n// binary\
    \ search, finds the border of determ\ntemplate <typename T = long long>\nT find_border(T\
    \ ok, T ng, const std::function<bool(T)> determ) {\n    while (abs(ok - ng) >\
    \ 1) {\n        T mid = (ok + ng) / 2;\n        if (determ(mid)) {\n         \
    \   ok = mid;\n        } else {\n            ng = mid;\n        }\n    }\n   \
    \ return ok;\n}\n"
  code: "#include <functional>\n\n// binary search, finds the border of determ\ntemplate\
    \ <typename T = long long>\nT find_border(T ok, T ng, const std::function<bool(T)>\
    \ determ) {\n    while (abs(ok - ng) > 1) {\n        T mid = (ok + ng) / 2;\n\
    \        if (determ(mid)) {\n            ok = mid;\n        } else {\n       \
    \     ng = mid;\n        }\n    }\n    return ok;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: algo/binary_search.hpp
  requiredBy: []
  timestamp: '2024-05-25 15:39:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/binary_search.test.cpp
documentation_of: algo/binary_search.hpp
layout: document
redirect_from:
- /library/algo/binary_search.hpp
- /library/algo/binary_search.hpp.html
title: algo/binary_search.hpp
---
