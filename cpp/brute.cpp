#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include "io.hpp"
#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;

#define each(i, a) for (auto &i : a)
#define all(x) (x).begin(), (x).end()
#define cmin(a, b) a = min(a, b)
#define cmax(a, b) a = max(a, b)

// #define TESTCASES
// #define FILES

// Random <= 1e9
mt19937 mt(time(nullptr));

int getRand() {
    return mt();
}

void solve(int &t) {
    int n;
    cin >> n;

    vector<int> a(n);
    cin >> a;

    int mn = INT_MAX, mx = INT_MIN;
    each(i, a) {
      mn = min(mn, i);
      mx = max(mx, i);
    }

    cout << mn << ' ' << mx;
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

    for (int i = 1; i <= t; i++) {
        solve(i);
        cout << "\n";
    }

    #ifdef TIME
        cout << setprecision(3) << fixed << (ld)(clock() - tt) / CLOCKS_PER_SEC;
    #endif
    
    return 0;
}
