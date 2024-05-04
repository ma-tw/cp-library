#include <vector>
using namespace std;

template<typename T = long long>
struct CumlSum2D {
    CumlSum2D(size_t h, size_t w) : _h(h), _w(w), _s(h + 1, vector<T>(w + 1)), _a(h, vector<T>(w)), ready(false) {}
    CumlSum2D(vector<vector<T>> a) : _h(a.size()), _w(a.empty() ? 0 : a[0].size()), _s(_h, vector<T>(_w)), _a(a), ready(false) {}
    void assign(unsigned int i, unsigned int j, T x) {
        if (_a[i][j] != x) ready = false;
        _a[i][j] = x;
    }

    // [row_low, row_high), [col_low, col_high)
    // O(hw * (calls after changes))
    T sum(unsigned int row_low, unsigned int col_low, unsigned int row_high, unsigned int col_high) {
        if (!ready) {
            for (int i = 0; i < _h; i++) {
                for (int j = 0; j < _w; j++) {
                    _s[i + 1][j + 1] = _a[i][j];
                }
            }
            for (int i = 0; i < _h; i++) {
                for (int j = 0; j < _w; j++) {
                    _s[i + 1][j + 1] += _s[i][j + 1] + _s[i + 1][j] - _s[i][j];
                }
            }
            ready = true;
        }
        return _s[row_high][col_high] + _s[row_low][col_low] - _s[row_high][col_low] - _s[row_low][col_high];
    }
    private:
    int _h, _w;
    vector<vector<T>> _s, _a;
    bool ready;
};
