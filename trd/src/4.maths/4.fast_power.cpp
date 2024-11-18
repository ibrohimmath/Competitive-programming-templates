int binpow(int a, int n, int mod = 1e9 + 7) {
    if (!a) {
        return 0;
    }
    if (!n) {
        return 1;
    }
    int res = 1;
    
    while (n) {
        if (n & 1) res = res * a % mod;
        n >>= 1;
        a = a * a % mod;
    }
    
    return res;
}
