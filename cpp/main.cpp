#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include "io.hpp"
// #include "debug.hpp"
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
// #define TIME

// Random <= 1e9
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);

int getRand() {
    return mt();
}

int n, k, m;
vector<int> a;
vector<int> counter;
// Maydondagi avtomatlar
set<int> st;
// prioritetga tushunvchi avtomatlar to'plami
map< int, set<int> > mp;

bool has(set<int> &st, int x) {
    if (st.find(x) != st.end()) {
        return true;
    }
    return false;
}

void decreaseOccurence(int x) {
    int prevTimes = counter[x];
    if (has(mp[prevTimes], x)) {
        mp[prevTimes].erase(x);
    }
    if (!mp[prevTimes].size()) {
        mp.erase(mp.find(prevTimes));
    }

    if (prevTimes > 0) {
        int currTimes = --counter[x];
        mp[currTimes].insert(x);
        st.insert(x);
    }
}

void eliminate() {
    while (!(mp.begin()->second).size()) {
        mp.erase(mp.begin());
    }
    each(item, (mp.begin()->second)) {
        if (has(st, item)) {
            st.erase(item);
            (mp.begin()->second).erase(item);
            return;
        }
    }
    if (!(mp.begin()->second).size()) {
        mp.erase(mp.begin());
    }
}

void outputMap() {
    for (auto [key, sett] : mp) {
        cout << key << " -> ";
        each(item, sett) cout << item << ' ';
        cout << "\n";
    }
    cout << "------\n";
}

void solve(int &t) {
    cin >> m >> k >> n;

    a.resize(n);
    counter.resize(m + 1);
    each(i, a) {
        cin >> i;
        counter[i]++;
    }

    int ans = 0;
    each(item, a) {
        if (has(st, item)) {
            decreaseOccurence(item);
        } else if (st.size() < k) {
            decreaseOccurence(item);
            ans++;
        } else {
            decreaseOccurence(item);
            eliminate();
            ans++;
        }
        // outputMap();
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
