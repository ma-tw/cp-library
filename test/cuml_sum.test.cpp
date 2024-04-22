#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <bits/stdc++.h>
#include "../algo/cuml_sum.hpp"
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    CumlSum s(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.assign(i, x);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << s.sum(l, r) << endl;
    }
}