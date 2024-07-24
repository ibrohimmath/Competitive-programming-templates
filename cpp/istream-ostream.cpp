// vector input (cin >> a)
istream& operator>> (istream& in, vector<int>& a) {
    for (auto &i : a) in >> i;
    return in;
}

// vector output (cout << a)
ostream& operator<< (ostream& out, const vector<int>& a) {
    for (auto &i : a) out << i << ' ';
    out << "\n";
    return out;
}
