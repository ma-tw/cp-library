#include <vector>
#include <type_traits>
using namespace std;

template<typename T>
struct CumlSum {
    static_assert(!is_same<T, int>::value);
    CumlSum(size_t n) : s(n + 1), a(n), ready(false) {}
    CumlSum(vector<T> a) : s(a.size() + 1), a(a), ready(false) {}
    void assign(unsigned int p, T x) {
        if (a[p] != x) ready = false;
        a[p] = x;
    }

    // [l, r)
    // O(n * (calls after changes))
    T sum(unsigned int l, unsigned int r) {
        if (!ready) {
            for (int i = 0; i < (int) s.size() - 1; i++) {
                s[i + 1] = s[i] + a[i];
            }
            ready = true;
        }
        return s[r] - s[l];
    }
    private:
    vector<T> s, a;
    bool ready;
};

////////////////// vector<int> 渡しちゃだめ ////////////////////////
