---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/binomial.hpp
    title: math/binomial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "#line 1 \"test/binomial.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 1 \"math/binomial.hpp\"\
    \n#include <atcoder/modint>\n#line 3 \"math/binomial.hpp\"\nusing namespace std;\n\
    \n// requires that mod p is prime\n// 1 <= k <= n <= 1e7\n// build O(n_max), call\
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
    };\n#line 5 \"test/binomial.test.cpp\"\n\nint main() {\n    int t, m;\n    cin\
    \ >> t >> m;\n    BinomNSmall binom(int(1e7), m);\n    for (int i = 0; i < t;\
    \ i++) {\n        int n, k;\n        cin >> n >> k;\n        cout << binom(n,\
    \ k).val() << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../math/binomial.hpp\"\
    \n\nint main() {\n    int t, m;\n    cin >> t >> m;\n    BinomNSmall binom(int(1e7),\
    \ m);\n    for (int i = 0; i < t; i++) {\n        int n, k;\n        cin >> n\
    \ >> k;\n        cout << binom(n, k).val() << endl;\n    }\n}"
  dependsOn:
  - math/binomial.hpp
  isVerificationFile: true
  path: test/binomial.test.cpp
  requiredBy: []
  timestamp: '2024-05-25 14:45:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/binomial.test.cpp
layout: document
redirect_from:
- /verify/test/binomial.test.cpp
- /verify/test/binomial.test.cpp.html
title: test/binomial.test.cpp
---
