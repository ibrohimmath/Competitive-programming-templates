#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)((a).size())
#define debug(x) cout << #x << ' ' << x << "\n";
#define each(i, a) for (auto &i : a)

// mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename... Args>
void out(Args... args) {
    ((cout << args << ' '), ...) << '\n';
}

// #define LEETCODE
void leet() {
}

// #define FILES
// #define TESTCASES
void solve(int &t) {

}

int32_t main() {
    // cin.tie(0)->sync_with_stdio(0);

    #ifdef LEETCODE
        leet();
    #endif

    #ifdef FILES
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    #ifdef TESTCASES
        cin >> t;
    #endif

    for (int i = 1; i <= t; i++) {
        solve(i);
        cout << "\n";
    }

    return 0;
}
