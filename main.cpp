#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(), (x).end()
#define ieach(i, a) for (auto &i : a)
#define each(i, a) for (const auto &i : a)

const int MOD = 1e9 + 7;
const int N = 2e5 + 1;

// #define TIME
void solve() {

}


// #define TESTCASES
// #define FILES
int main(void) {
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
    while (t-- > 0) {
        solve();
        cout << "\n";
    }
    #ifdef TIME
        cout << setprecision(3) << fixed << (ld)(clock() - tt) / CLOCKS_PER_SEC;
    #endif
    return 0;
}