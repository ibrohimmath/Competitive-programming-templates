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

    template <typename... Args>
    void readln(Args&... args) {
        ((std::cin >> args), ...);
    }
    
    template <typename... Args>
    void println(Args... args) {
        ((std::cout << args << ' '), ...);
        std::cout << '\n';
    }
}

// ##################################################################################################################
// CONSTANTS
constexpr const int MOD = 1e9 + 7;

// ##################################################################################################################
// OTHER
using namespace IO;

// ##################################################################################################################
// LEETCDODE

// #define LEETCODE
void leet() {

}

// ##################################################################################################################
// SOLUTION

struct StringCalc {
    stack<int> nums; 
    stack<char> ops;

    StringCalc() {}
    
    bool is_number(char c) {
        return '0' <= c && c <= '9';
    }

    bool is_op(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    int prior(char c) {
        if (c == '+' || c == '-') return 1;
        if (c == '*' || c == '/') return 2;
        return 0;
    }

    int apply(char op) {
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();

        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        if (op == '/') return a / b;
        return 0;
    }

    int calculate(string express) {
        for (int i = 0; i < express.size(); i++) {
            if (is_number(express[i])) {
                int num = 0;
                
                int j = i;
                while (j < express.size() && is_number(express[j])) {
                    num = num * 10 + (express[j] - '0');
                    // println(express[j]);
                    j++;
                }

                nums.push(num);
                
                if (j > i) i = j - 1;
            } else if (express[i] == '(') {
                ops.push(express[i]);
            } else if (is_op(express[i])) {
                println(express[i]);
                while (sz(ops) > 0 && prior(ops.top()) >= prior(express[i])) {
                    int calc_num = apply(ops.top()); ops.pop();
                    nums.push(calc_num);
                }
                ops.push(express[i]);
            } else {
                while (sz(ops) > 0 && ops.top() != '(') {
                    int calc_num = apply(ops.top()); ops.pop();
                    nums.push(calc_num);
                }
                if (sz(ops) > 0)
                    ops.pop();
            }
        }
        
        while (sz(ops) > 0) {
            int calc_num = apply(ops.top()); ops.pop();
            nums.push(calc_num);
        }
        
        return nums.top();
    }
};


// #define FILES
// #define TESTCASES
void solve(int &t) {
    StringCalc calc;
    println(calc.calculate("(1+2*3)*3"));
}

int32_t main() {
    IO::init();

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
        // std::cout << "\n";
    }

    return 0;
}
