ll binpow(ll a, ll n, ll mod = 1e9 + 7) {
    if (!a) {
        return 0;
    }
    if (!n) {
        return 1;
    }
    ll res = 1;
    
    while (n) {
        if (n & 1) res = res * a % mod;
        n >>= 1;
        a = a * a % mod;
    }
    
    return res;
}

vector<int> sieve(int n) {
    vector<int> primes;
    vector<char> tub(n, 1);
    
    for (int i = 2; i * i <= n; i++) {
        if (tub[i]) {
            for (int j = i * i; j <= n; j += i) {
                tub[j] = 0;
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        if (tub[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

