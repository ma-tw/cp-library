#include <vector>
using namespace std;

#include "cuml_sum.hpp"
template<typename T = long long>
struct Imos {
    Imos(size_t n) : _cs(n) {}

    // [l, r)
    void add(unsigned int l, unsigned int r, int value) {
        _cs.assign(l, value);
        _cs.assign(r, -value);
    }

    T get(unsigned int p) {
        return _cs.sum(p, p + 1);
    }
    private:
    CumlSum<T> _cs;
};
