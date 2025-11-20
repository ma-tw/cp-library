#include <vector>
using namespace std;

template<typename T = long long>
struct CumlSum {
    CumlSum(size_t n) : _s(n + 1), _a(n), ready(false) {}
    CumlSum(vector<T> a) : _s(a.size() + 1), _a(a), ready(false) {}
    void assign(unsigned int p, T x) {
        if (_a[p] != x) ready = false;
        _a[p] = x;
    }

    // [l, r)
    // O(n * (calls after changes))
    T sum(unsigned int l, unsigned int r) {
        if (!ready) {
            for (int i = 0; i < (int) _s.size() - 1; i++) {
                _s[i + 1] = _s[i] + _a[i];
            }
            ready = true;
        }
        return _s[r] - _s[l];
    }
    private:
    vector<T> _s, _a;
    bool ready;
};

////////////////// vector<int> 渡しちゃだめ ////////////////////////