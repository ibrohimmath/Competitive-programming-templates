void eratosfen(int n) {
    vector<bool> sieve(n + 1, true);

    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i; i <= n) {
        if (sieve[i]) {
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = false;
            }
        }
    }
}
