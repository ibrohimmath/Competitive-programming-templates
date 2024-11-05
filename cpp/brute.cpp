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

// #define TESTCASES
// #define FILES
// #define TIME

// Random <= 1e9
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);

int getRand() {
    return mt();
}

void output(int m, vector<int> counter) {
    for (int i = 1; i <= m; i++) {
        cout << i << ' ' << counter[i] << "\n";
    }
}

void solve(int &t) {
    int m, k, n;
    cin >> m >> k >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Track current weapons on ranges
    set<int> ranges;
    // Track next occurrence and count of remaining uses
    vector<int> next(m + 1, n);
    vector<int> remaining(m + 1, 0);
    
    // Calculate remaining uses for each weapon
    for (int i = 0; i < n; i++) {
        remaining[a[i]]++;
    }
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        // Update next occurrence for each weapon
        for (int j = i; j < n; j++) {
            if (next[a[j]] == n) {
                next[a[j]] = j;
            }
        }
        
        int curr = a[i];
        remaining[curr]--;
        
        if (ranges.count(curr)) continue;
        
        if (ranges.size() < k) {
            ranges.insert(curr);
            ans++;
            continue;
        }
        
        // Need to make a swap - find best weapon to remove
        int to_remove = -1;
        int worst_score = -1;
        
        for (int weapon : ranges) {
            // Score based on next occurrence and remaining uses
            int score = next[weapon] * n + remaining[weapon];
            if (score > worst_score) {
                worst_score = score;
                to_remove = weapon;
            }
        }
        
        if (to_remove != -1 && 
            (next[to_remove] > i || remaining[to_remove] == 0)) {
            ranges.erase(to_remove);
            ranges.insert(curr);
            ans++;
        }
        
        // Reset next positions
        for (int j = 1; j <= m; j++) {
            next[j] = n;
        }
    }
    
    cout << ans;
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
