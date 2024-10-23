// IO
// Vector input and output (cin >> a && cout << a)
istream& operator>> (istream& in, vector<int>& a) {
    for (auto &i : a) in >> i;
    return in;
}

ostream& operator<< (ostream& out, const vector<int>& a) {
    for (auto &i : a) out << i << ' ';
    out << "\n";
    return out;
}
