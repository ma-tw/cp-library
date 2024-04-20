#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"
#include <bits/stdc++.h>
using namespace std;
#include "../math/prime_factor.hpp"

int main() {
    long long n;
    cin >> n;
    auto pf = prime_factor(n);
    cout << n << ":";
    for (auto [x, y] : pf) {
        for (int i = 0; i < y; i++) cout << " " << x;
    }
    cout << endl;
}