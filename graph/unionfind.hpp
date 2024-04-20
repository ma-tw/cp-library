#include <vector>
#include <utility>
#include <cassert>

struct UnionFind {
    private:
    int n;
    std::vector<int> par, rank, size_mem;

    public:
    UnionFind(int _n) : n(_n), par(_n, -1), rank(_n, 0), size_mem(_n, 1) {}

    int root(int x) {
        assert(0 <= x && x < n);

        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool same(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);

        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);

        int rx = root(x), ry = root(y);
        if (rx == ry) return false;

        // ry のほうが小さいようにする
        if (rank[rx] < rank[ry]) std::swap(rx, ry);

        // ry が rx の子とする
        par[ry] = rx;
        if (rank[rx] == rank[ry]) rank[rx]++;
        size_mem[rx] += size_mem[ry];

        return true;
    }

    int size(int x) {
        assert(0 <= x && x < n);
        return size_mem[root(x)];
    }  
};

struct UnionFind2D {
    private:
    int h, w;
    UnionFind uf;
    
    public:
    UnionFind2D(int _h, int _w) : h(_h), w(_w), uf(_h * _w) {}

    std::pair<int, int> root(int i, int j) {
        int tmp = uf.root(i * w + j);
        return std::make_pair(tmp / w, tmp % w);
    }

    bool same(int i1, int j1, int i2, int j2) {
        return uf.same(i1 * w + j1, i2 * w + j2);
    }

    bool unite(int i1, int j1, int i2, int j2) {
        return uf.unite(i1 * w + j1, i2 * w + j2);
    }

    int size(int i, int j) {
        return uf.size(i * w + j);
    }
};