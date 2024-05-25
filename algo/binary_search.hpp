#include <functional>

// binary search, finds the border of determ
template <typename T = long long>
T find_border(T ok, T ng, const std::function<bool(T)> determ) {
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
