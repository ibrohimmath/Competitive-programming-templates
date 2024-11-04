#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <string>
#include <utility>

using namespace std;

inline void __print(bool x) { cerr << (x ? "true" : "false"); }
inline void __print(char x) { cerr << '\'' << x << '\''; }
inline void __print(const char* x) { cerr << "\"" << x << "\""; }
inline void __print(const std::string& x) { cerr << "\"" << x << "\""; }
inline void __print(int x) { cerr << x; }
inline void __print(long long x) { cerr << x; }
inline void __print(unsigned long long x) { cerr << x; }
inline void __print(float x) { cerr << x; }
inline void __print(double x) { cerr << x; }
inline void __print(long double x) { cerr << x; }

template <typename T>
inline void __print(const T& x) {
    cerr << "{"; int f = 0;
    for (auto& i : x) cerr << (f++ ? ", " : ""), __print(i);
    cerr << "}";
}

inline void _print() { cerr << "]\n"; }

template <typename T, typename... V>
inline void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

#define debug(x...) cerr << "[" << #x << "] = ["; _print(x);

#endif // DEBUG_H
