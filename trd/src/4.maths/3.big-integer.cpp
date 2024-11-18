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
        reverse(aint(a));
        reverse(aint(b));
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
        reverse(aint(c));
        return Int(stripZeros(c));
    }

    Int operator-(const Int& obj){
        string a = s, b = obj.s;
        if(a == b) return Int("0");
        reverse(aint(a));
        reverse(aint(b));
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
        reverse(aint(c));
        return Int(stripZeros(c));
    }

    Int operator*(const Int &obj){
        string a = s, b = obj.s;
        reverse(aint(a));
        reverse(aint(b));
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
        reverse(aint(c));
        return Int(stripZeros(c));
    }

    Int operator/(const int &n){
        s = stripZeros(s);
        string ans = "";
        int num = 0;
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