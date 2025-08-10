#include <vector>
using namespace std;

// requires that mod p is prime
// 1 <= k <= n <= 1e7
// build O(n_max), call O(1)
struct BinomNSmall {
    BinomNSmall(int n_max, int mod) : fact(n_max + 1), fact_inv(n_max + 1), inv(n_max + 1), MOD(mod) {
        fact[0] = fact[1] = 1;
        fact_inv[0] = fact_inv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i <= n_max; i++) {
            fact[i] = fact[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
        }
    }
    long long operator() (int n, int k) {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fact[n] * fact_inv[k] % MOD * fact_inv[n - k] % MOD;
    }
    private:
    vector<long long> fact, fact_inv, inv;
    const int MOD;
};

// n is const
// 1 <= n <= 1e9
// 1 <= k <= 1e7
// build O(k_max * log(mod)), call O(1)
struct BinomNLarge {
    BinomNLarge(long long n, int k_max, int mod) : binom_(k_max + 1), n_(n), k_max_(k_max), MOD(mod) {
        binom_[0] = 1;
        for (int i = 1; i <= k_max; i++) {
            long long ni = n_ - i + 1;
            ni %= MOD;
            if (ni < 0) ni += MOD;
            binom_[i] = binom_[i - 1] * ni % MOD * modpow(i, MOD - 2) % MOD;
        }
    }
    long long operator() (int k) {
        if (n_ < k) return 0;
        if (n_ < 0 || k < 0) return 0;
        if (k > k_max_) return 0;
        return binom_[k];
    }
    private:
    long long modpow(long long a, long long b) {
        long long p = a, res = 1;
        while (b > 0) {
            if (b & 1) res = res * p % MOD;
            p = p * p % MOD;
            b >>= 1;
        }
        return res;
    }
    vector<long long> binom_;
    long long n_;
    int k_max_;
    const int MOD;
};