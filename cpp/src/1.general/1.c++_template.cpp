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

<<<<<<< HEAD:cpp/sol.cpp
// #define READ_MAIN
// #define TESTCASES
// #define FILES
// #define TIME

// Random <= 1e9
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);
=======
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
>>>>>>> 9ee80bd (TRD changed):cpp/src/1.general/1.c++_template.cpp

int getRand() {
    return mt();
}

<<<<<<< HEAD:cpp/sol.cpp
void readMain() {

}

void solve(int &t) {
    cout << "Hello world";
=======
void readMain() {}

// #define READ_MAIN
// #define TESTCASES
// #define FILES
// #define TIME
void solve(int &t) {

>>>>>>> 9ee80bd (TRD changed):cpp/src/1.general/1.c++_template.cpp
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
