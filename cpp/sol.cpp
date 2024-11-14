#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ld = long double;
#define each(i, a) for (auto &i : a)
#define all(x) (x).begin(), (x).end()
#define cmin(a, b) a = min(a, b)
#define cmax(a, b) a = max(a, b)

#ifndef ONLINE_JUDGE
    #include "io.hpp"
    #include "debug.hpp"
#endif

// #define READ_MAIN
// #define TESTCASES
// #define FILES
// #define TIME

// Random <= 1e9
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);

int getRand() {
    return mt();
}

void readMain() {

}

void solve(int &t) {
    cout << "Hello world";
}

int32_t main(void) {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    clock_t tt = clock();

    #ifdef FILES
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    #ifdef TESTCASES
        cin >> t;
    #endif

    #ifdef READ_MAIN
        readMain();
    #endif

    for (int i = 1; i <= t; i++) {
        solve(i);
        cout << "\n";
    }

    #ifdef TIME
        cout << setprecision(3) << fixed << (ld)(clock() - tt) / CLOCKS_PER_SEC;
    #endif
    
    return 0;
}
