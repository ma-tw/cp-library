vector<bool> prime_table(ll n)
{
    vector<bool> prime(n + 1, true);
    if (n >= 0) prime[0] = false;
    if (n >= 1) prime[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (!prime[i]) continue;
        for (ll j = i * i; j <= n; j += i) {
            prime[j] = false;
        }
    }
    return prime;
}
vector<ll> enumerate_primes(ll n)
{
    if (n <= 1) return {};
    auto d = prime_table(n);
    vector<ll> primes;
    primes.reserve(count(begin(d), end(d), true));
    for (ll i = 0; i < (ll) d.size(); i++) {
        if (d[i]) primes.push_back(i);
    }
    return primes;
}
