#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ld = long double;
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)((a).size())
#define debug(x) std::cerr << #x << ' ' << x << "\n";
#define each(i, a) for (auto &i : a)

// mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());

// ##################################################################################################################
// NAMESPACES
namespace IO {
    void init(bool fast = true) {
        if (fast) {
            // std::cin.tie(0)->sync_with_stdio(0);
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
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

// ##################################################################################################################
// CONSTANTS
constexpr const int MOD = 1e9 + 7;

// ##################################################################################################################
// OTHER
using namespace IO;

// Read array compatible with C++ versions before C++20 
// generate(all(a), read<int>); 

// ########################################################################;##########################################
// LEETCDODE


#define LEETCODE
void leet() {
    // Solution sol;
}

// ##################################################################################################################
// SOLUTION



// #define FILES
// #define TESTCASES
void solve(int &t) {

}

int32_t main() {
    IO::init(true);

    #ifdef LEETCODE
        leet();
    #endif

    #ifdef FILES
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    #ifdef TESTCASES
        std::cin >> t;
    #endif

    for (int i = 1; i <= t; i++) {
        solve(i);
        std::cout << "\n";
    }

    return 0;
}
