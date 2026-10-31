#include <cassert>
#include <set>
#include <utility>
using namespace std;

struct IntervalSet {
    using ll = long long;
    const ll LINF = 1LL << 60;

    set<pair<ll, ll>> st;
    
    IntervalSet() {
        st.emplace(LINF, LINF);
        st.emplace(-LINF, -LINF);
    }

    bool covered(ll l, ll r) {
        assert(l < r);
        auto it = prev(st.upper_bound({l, LINF}));
        return it->first <= l && r <= it->second;
    }

    bool covered(ll x) {
        return covered(x, x + 1);
    }

    pair<ll, ll> covered_by(ll l, ll r) {
        assert(l < r);
        auto it = prev(st.upper_bound({l, LINF}));
        if (it->first <= l && r <= it->second) return *it;
        return {-LINF, -LINF};
    }

    ll insert(ll l, ll r) {
        assert(l < r);
        auto it = prev(st.upper_bound({l, LINF}));
        if (it->first <= l && r <= it->second) return 0LL;

        ll sum_erased = 0LL;
        if (it->first <= l && l <= it->second) {
            l = it->first;
            sum_erased += it->second - it->first;
            it = st.erase(it);
        } else {
            it = next(it);
        }
        while (r > it->second) {
            sum_erased += it->second - it->first;
            it = st.erase(it);
        }
        if (it->first <= r && r <= it->second) {
            sum_erased += it->second - it->first;
            r = it->second;
            st.erase(it);
        }
        st.emplace(l, r);
        return r - l - sum_erased;
    }

    ll insert(ll x) {
        return insert(x, x + 1);
    }

    ll erase(ll l, ll r) {
        assert(l < r);
        auto it = prev(st.upper_bound({l, LINF}));
        if (it->first <= l && r <= it->second) {
            if (it->first < l) st.emplace(it->first, l);
            if (r < it->second) st.emplace(r, it->second);
            st.erase(it);
            return r - l;
        }

        ll ret = 0LL;
        if (it->first <= l && l < it->second) {
            ret += it->second - l;
            if (it->first < l) st.emplace(it->first, l);
            it = st.erase(it);
        } else {
            it = next(it);
        }
        while (it->second <= r) {
            ret += it->second - it->first;
            it = st.erase(it);
        }

        if (it->first < r && r <= it->second) {
            ret += r - it->first;
            if (r < it->second) st.emplace(r, it->second);
            st.erase(it);
        }
        return ret;
    }

    ll erase(ll x) {
        return erase(x, x + 1);
    }

    // number of intervals
    int size() {
        return (ll) st.size() - 2;
    }

    ll mex(ll x=0) {
        auto it = prev(st.upper_bound({x, LINF}));
        if (it->first <= x && x <= it->second) return it->second;
        else return x;
    }
};

// reference: https://mugen1337.hatenablog.com/entry/2020/10/14/134022
// https://mugen1337.github.io/procon/DataStructure/RangeSet.hpp
