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

// #ifndef ONLINE_JUDGE
//     #include "debug.hpp"
// #endif

mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());

int rand(int a, int b) {
  return a + getRand() % (b - a + 1);
}

void gen_array(int a, int b, int n) {
    // cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << rand(a, b) << " ";
    }
}

int getRand() {
    return mt();
}

void readMain() {}

// #define READ_MAIN
// #define TESTCASES
// #define FILES
// #define TIME
void solve(int &t) {

}

int32_t main(void) {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    clock_t tt = clock();

    #ifdef FILES
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    #ifdef READ_MAIN
        readMain();
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
