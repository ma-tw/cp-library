#include <vector>
#include <type_traits>
using namespace std;

template<typename T>
struct CumlSum2D {
    static_assert(!is_same<T, int>::value);
    CumlSum2D(size_t h, size_t w) : h(h), w(w), s(h + 1, vector<T>(w + 1)), a(h, vector<T>(w)), ready(false) {}
    CumlSum2D(vector<vector<T>> a) : h(a.size()), w(a.empty() ? 0 : a[0].size()), s(h + 1, vector<T>(w + 1)), a(a), ready(false) {}
    void assign(unsigned int i, unsigned int j, T x) {
        if (a[i][j] != x) ready = false;
        a[i][j] = x;
    }

    // [row_low, row_high), [col_low, col_high)
    // O(hw * (calls after changes))
    T sum(unsigned int row_low, unsigned int col_low, unsigned int row_high, unsigned int col_high) {
        if (!ready) {
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    s[i + 1][j + 1] = a[i][j];
                }
            }
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    s[i + 1][j + 1] += s[i][j + 1] + s[i + 1][j] - s[i][j];
                }
            }
            ready = true;
        }
        return s[row_high][col_high] + s[row_low][col_low] - s[row_high][col_low] - s[row_low][col_high];
    }
    private:
    int h, w;
    vector<vector<T>> s, a;
    bool ready;
};
