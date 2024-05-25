#define PROBLEM "https://atcoder.jp/contests/typical90/tasks/typical90_a"
#include <bits/stdc++.h>
#include "../algo/binary_search.hpp"
using namespace std;

int main() {
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << find_border<int>(0, 1e9, [&](int x) {
        int cnt = 0;
        int last = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] - last >= x) {
                cnt++;
                last = a[i];
            }
        }
        cnt += l - last >= x;
        return cnt >= k + 1;
    }) << endl;
}