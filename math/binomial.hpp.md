---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/binomial.test.cpp
    title: test/binomial.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/binomial.hpp\"\n#include <atcoder/modint>\n#include\
    \ <vector>\nusing namespace std;\n\n// requires that mod p is prime\n// 1 <= k\
    \ <= n <= 1e7\n// build O(n_max), call O(1)\nstruct BinomNSmall {\n    BinomNSmall(int\
    \ n_max, int mod) : fact(n_max + 1), fact_inv(n_max + 1), inv(n_max + 1), MOD(mod)\
    \ {\n        atcoder::modint::set_mod(mod);\n        fact[0] = fact[1] = 1;\n\
    \        fact_inv[0] = fact_inv[1] = 1;\n        inv[1] = 1;\n        for (int\
    \ i = 2; i <= n_max; i++) {\n            fact[i] = fact[i - 1] * i;\n        \
    \    inv[i] = -inv[MOD % i] * (MOD / i);\n            fact_inv[i] = fact_inv[i\
    \ - 1] * inv[i];\n        }\n    }\n    atcoder::modint operator() (int n, int\
    \ k) {\n        if (n < k) return 0;\n        if (n < 0 || k < 0) return 0;\n\
    \        return fact[n] * fact_inv[k] * fact_inv[n - k];\n    }\n    private:\n\
    \    vector<atcoder::modint> fact, fact_inv, inv;\n    const int MOD;\n};\n\n\
    // n is const\n// 1 <= n <= 1e9\n// 1 <= k <= 1e7\n// build O(k), call O(1)\n\
    struct BinomNLarge {\n    BinomNLarge(int n, int k_max, int mod) : binom_(k_max\
    \ + 1), n_(n), k_max_(k_max) {\n        atcoder::modint::set_mod(mod);\n     \
    \   binom_[0] = 1;\n        for (int i = 1; i <= k_max; i++) {\n            binom_[i]\
    \ = binom_[i - 1] * (n - i + 1) / i;\n        }\n    }\n    atcoder::modint operator()\
    \ (int k) {\n        if (n_ < k) return 0;\n        if (n_ < 0 || k < 0) return\
    \ 0;\n        if (k > k_max_) return 0;\n        return binom_[k];\n    }\n  \
    \  private:\n    vector<atcoder::modint> binom_;\n    int n_, k_max_;\n};\n"
  code: "#include <atcoder/modint>\n#include <vector>\nusing namespace std;\n\n//\
    \ requires that mod p is prime\n// 1 <= k <= n <= 1e7\n// build O(n_max), call\
    \ O(1)\nstruct BinomNSmall {\n    BinomNSmall(int n_max, int mod) : fact(n_max\
    \ + 1), fact_inv(n_max + 1), inv(n_max + 1), MOD(mod) {\n        atcoder::modint::set_mod(mod);\n\
    \        fact[0] = fact[1] = 1;\n        fact_inv[0] = fact_inv[1] = 1;\n    \
    \    inv[1] = 1;\n        for (int i = 2; i <= n_max; i++) {\n            fact[i]\
    \ = fact[i - 1] * i;\n            inv[i] = -inv[MOD % i] * (MOD / i);\n      \
    \      fact_inv[i] = fact_inv[i - 1] * inv[i];\n        }\n    }\n    atcoder::modint\
    \ operator() (int n, int k) {\n        if (n < k) return 0;\n        if (n < 0\
    \ || k < 0) return 0;\n        return fact[n] * fact_inv[k] * fact_inv[n - k];\n\
    \    }\n    private:\n    vector<atcoder::modint> fact, fact_inv, inv;\n    const\
    \ int MOD;\n};\n\n// n is const\n// 1 <= n <= 1e9\n// 1 <= k <= 1e7\n// build\
    \ O(k), call O(1)\nstruct BinomNLarge {\n    BinomNLarge(int n, int k_max, int\
    \ mod) : binom_(k_max + 1), n_(n), k_max_(k_max) {\n        atcoder::modint::set_mod(mod);\n\
    \        binom_[0] = 1;\n        for (int i = 1; i <= k_max; i++) {\n        \
    \    binom_[i] = binom_[i - 1] * (n - i + 1) / i;\n        }\n    }\n    atcoder::modint\
    \ operator() (int k) {\n        if (n_ < k) return 0;\n        if (n_ < 0 || k\
    \ < 0) return 0;\n        if (k > k_max_) return 0;\n        return binom_[k];\n\
    \    }\n    private:\n    vector<atcoder::modint> binom_;\n    int n_, k_max_;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: math/binomial.hpp
  requiredBy: []
  timestamp: '2024-05-25 14:45:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/binomial.test.cpp
documentation_of: math/binomial.hpp
layout: document
redirect_from:
- /library/math/binomial.hpp
- /library/math/binomial.hpp.html
title: math/binomial.hpp
---
