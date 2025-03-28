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

void leetcode() {

}

// #define FILES
// #define TESTCASES
// #define LEETCODE
void solve(int &t) {
    int n; cin >> n;

    vector<int> a(n + 1); 
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= n; c++) {
            
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    #ifdef LEETCODE
        leetcode();
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
