#pragma GCC optimize("Ofast,unroll-loops")
#include "bits/stdc++.h"

using ll = long long;
using ld = long double;
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)((a).size())
#define debug(x) std::cerr << #x << ' ' << x << "\n";
#define each(item, a) for (auto& item : a)

// mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());

namespace IO {
    void init(bool fast = true) {
        if (fast) {
            std::ios::sync_with_stdio(false);
            std::cin.tie(nullptr);
        }
    }

    template <typename T>
    T read() {
        T x;
        std::cin >> x;
        return x;
    }

    template <typename... Args>
    void readln(Args&... args) {
        ((std::cin >> args), ...);
    }

    template <typename... Args>
    void println(Args... args) {
        ((std::cout << args << ' '), ...) << '\n';
    }
}

constexpr const int MOD = 1e9 + 7;



// #define FILES
// #define TESTCASES
void solve(int &t) {

}

int32_t main() {
    IO::init(true);

    #ifdef FILES
        std::freopen("input.txt", "r", stdin);
        std::freopen("output.txt", "w", stdout);
    #endif

    int tests = 1;
    #ifdef TESTCASES
        std::cin >> tests;
    #endif

    for (int t = 1; t <= tests; ++t) {
        solve(t);
    }

    return 0;
}