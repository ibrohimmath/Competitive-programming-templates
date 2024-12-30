#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ld = long double;
#define each(i, a) for (auto &i : a)
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define repr(i, b, a) for (int i = (b); i > (a); i--)
#define cmin(a, b) a = min(a, b)
#define cmax(a, b) a = max(a, b)

mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());

void readMain() {}
// #define READ_MAIN
// #define FILES
// #define TESTCASES
void solve(int &t) {
    int n;
    cin >> n;

    vector<int> a(n);   
    rep(i, 0, n) {
        cin >> a[i];
    }

    sort(all(a));

    rep(i, 0, n) {
        
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    #ifdef FILES
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
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

    return 0;
}