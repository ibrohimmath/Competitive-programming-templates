// Fastpow
ll binpow(ll a, ll n, ll mod = 1e9 + 7) {
    if (!a) {
        return 0;
    }
    if (!n) {
        return 1;
    }
    ll res = 1;
    
    while (n) {
        if (n & 1) res = res * a % mod;
        n >>= 1;
        a = a * a % mod;
    }
    
    return res;
}

// Sieve prime
vector<int> sieve(int n) {
    vector<int> primes;
    vector<char> tub(n, 1);
    
    for (int i = 2; i * i <= n; i++) {
        if (tub[i]) {
            for (int j = i * i; j <= n; j += i) {
                tub[j] = 0;
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        if (tub[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

// BigInt
struct Int{
    string s;
    Int() : s("0") {}
    Int(string s) : s(s) {}

    bool operator<(const Int& x){
        if(s.size() != x.s.size()) return s.size() < x.s.size();
        return s < x.s;
    }

    string stripZeros(string s){
        for(int i = 0; i < size(s); i++)
            if(s[i] != '0'){
                return s.substr(i);
            }
        return "0";
    }    

    Int operator+(const Int &obj){
        string a = s, b = obj.s;        
        int n = size(a), m = size(b);
        reverse(all(a));
        reverse(all(b));
        if(n < m) a += string(m - n, '0'), n = m;
        else b += string(n - m, '0'), m = n;
        string c = "";
        int dilda = 0;
        for(int i = 0; i < n; i++){
            int num = (dilda + a[i] - '0' + b[i] - '0');
            dilda = num / 10;
            num %= 10;
            c += char(num + '0');
        }
        if(dilda) c += char(dilda + '0');
        reverse(all(c));
        return Int(stripZeros(c));
    }

    Int operator-(const Int& obj){
        string a = s, b = obj.s;
        if(a == b) return Int("0");
        reverse(all(a));
        reverse(all(b));
        string c = "";
        int n = a.size(), m = b.size();
        if(n < m) a += string(m - n, '0'), n = m;
        else b += string(n - m, '0'), m = n;
        int dilda = 0;
        for(int i = 0; i < n; i++){
            int num = dilda + a[i] - b[i];
            if(num < 0){
                dilda = -1;
                num += 10;
            }else dilda = 0;
            c += char(num + '0');
        }
        reverse(all(c));
        return Int(stripZeros(c));
    }

    Int operator*(const Int &obj){
        string a = s, b = obj.s;
        reverse(all(a));
        reverse(all(b));
        int n = size(a), m = size(b);
        vector<int>ans(n + m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i + j] += (a[i] - '0') * (b[j] - '0');
            }
        }    
        string c = "";
        int dilda = 0;
        for(int i = 0; i < n + m; i++){
            int num = (dilda + ans[i]);
            c += char(num % 10 + '0');
            dilda = num / 10;
        }
        if(dilda) c += dilda;
        reverse(all(c));
        return Int(stripZeros(c));
    }

    Int operator/(const int &n){
        s = stripZeros(s);
        string ans = "";
        ll num = 0;
        for(int i = 0; i < size(s); i++){
            num = 10 * num + s[i] - '0';
            ans += char(num / n + '0');
            num %= n;
        }
        return Int(stripZeros(ans));
    }

    Int operator^(int n){
        Int a(s);
        Int c("1");
        while(n){
            if(n & 1) c = c * a;
            n >>= 1;
            a = a * a;    
        }
        return c;
    }

    friend istream& operator>> (istream& out, Int& obj);
    friend ostream& operator<< (ostream& out, const Int& obj);
};

istream& operator>> (istream& out, Int& obj){
    out >> obj.s;
    return out;
}

ostream& operator<< (ostream& out, const Int& obj){
    out << obj.s;
    return out;
}

