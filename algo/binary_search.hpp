#include <functional>

// binary search, finds the border of determ
template <typename T = long long, typename F>
T find_border(T ok, T ng, const F determ) {
    while (abs(ok - ng) > 1) {
        T mid = (ok + ng) / 2;
        if (determ(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}
