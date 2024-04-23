#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560"

#include <bits/stdc++.h>
#include "../algo/cuml_sum_2d.hpp"
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<string> a(h);
    for (int i = 0; i < h; i++) cin >> a[i];
    CumlSum2D sj(h, w), si(h, w), so(h, w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            sj.assign(i, j, a[i][j] == 'J');
            si.assign(i, j, a[i][j] == 'I');
            so.assign(i, j, a[i][j] == 'O');
        }
    }
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--;
        cout << sj.sum(a, b, c, d) << ' ' << so.sum(a, b, c, d) << ' ' << si.sum(a, b, c, d) << endl;
    }
}