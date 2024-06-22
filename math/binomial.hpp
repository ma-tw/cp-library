#pragma once

#include "../atcoder/modint"
#include <vector>
using namespace std;

// requires that mod p is prime
// 1 <= k <= n <= 1e7
// build O(n_max), call O(1)
struct BinomNSmall {
    BinomNSmall(int n_max, int mod) : fact(n_max + 1), fact_inv(n_max + 1), inv(n_max + 1), MOD(mod) {
        atcoder::modint::set_mod(mod);
        fact[0] = fact[1] = 1;
        fact_inv[0] = fact_inv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i <= n_max; i++) {
            fact[i] = fact[i - 1] * i;
            inv[i] = -inv[MOD % i] * (MOD / i);
            fact_inv[i] = fact_inv[i - 1] * inv[i];
        }
    }
    int operator() (int n, int k) {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return (fact[n] * fact_inv[k] * fact_inv[n - k]).val();
    }
    private:
    vector<atcoder::modint> fact, fact_inv, inv;
    const int MOD;
};

// n is const
// 1 <= n <= 1e9
// 1 <= k <= 1e7
// build O(k), call O(1)
struct BinomNLarge {
    BinomNLarge(int n, int k_max, int mod) : binom_(k_max + 1), n_(n), k_max_(k_max) {
        atcoder::modint::set_mod(mod);
        binom_[0] = 1;
        for (int i = 1; i <= k_max; i++) {
            binom_[i] = binom_[i - 1] * (n - i + 1) / i;
        }
    }
    int operator() (int k) {
        if (n_ < k) return 0;
        if (n_ < 0 || k < 0) return 0;
        if (k > k_max_) return 0;
        return binom_[k].val();
    }
    private:
    vector<atcoder::modint> binom_;
    int n_, k_max_;
};