#ifndef IO_H
#define IO_H

#include <iostream>
#include <vector>

using namespace std; // Avoid this in header files if possible, as it pollutes the global namespace.

template<typename T>
istream& operator>> (istream& in, vector<T>& a) {
    for (auto &i : a) in >> i;
    return in;
}

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& a) {
    for (auto &i : a) out << i << ' ';
    out << "\n";
    return out;
}

#endif // IO_H
