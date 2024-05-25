#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"
#include <bits/stdc++.h>
using namespace std;
#include "../math/binomial.hpp"

int main() {
    int t, m;
    cin >> t >> m;
    BinomNSmall binom(int(1e7), m);
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        cout << binom(n, k).val() << endl;
    }
}