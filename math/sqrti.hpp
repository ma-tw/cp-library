long long sqrti(long long x) {
    long long ok = 0, ng = 1LL << 31;
    while (ng - ok > 1) {
        long long mid = (ok + ng) / 2;
        if (mid * mid <= x) ok = mid;
        else ng = mid;
    }
    return ok;
}
