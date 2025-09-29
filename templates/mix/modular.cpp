// template<typename T>
// struct Modular {
//     static constexpr T MOD = (int)9_E + 7;

//     T x = 0;
//     Modular() {} 
//     Modular(int x))

//     T norm(int a) {
//         if (a > 0) a %= MOD;
//         if (a < 0) a = (a % MOD + MOD) % MOD;
//         return a;
//     }
// }

template<typename T> struct Modular {
	static const T mod = ( int ) 1e9 + 7;
 
	T x = 0;
	Modular(){}
	Modular( int x ){ this -> x = norm( x ); }
 
	T norm( int a ) { if( a > mod ) a %= mod; if( a < 0 ) a = ( a % mod + mod ); return a; }
	Modular norm( Modular m ){ return m.x = norm( m.x ); }
 
	Modular operator - () { return Modular( -x ); }
	Modular operator ++ () { return Modular( ++x ); }
 
	Modular & operator += ( const Modular &m ){ this -> x = norm( this -> x + m.x ); return *this; }
	Modular & operator -= ( const Modular &m ){ this -> x = norm( this -> x - m.x ); return *this; }
	Modular & operator *= ( const Modular &m ){ this -> x = ( 1ll * m.x % mod * this -> x ) % mod; return *this; }
	Modular & operator /= ( const Modular &m ){ return *this *= inv( m ); }
 
	Modular & operator += ( const int &x ){ this -> x = norm( this -> x + x ); return *this; }
	Modular & operator -= ( const int &x ){ this -> x = norm( this -> x - x ); return *this; }
	Modular & operator *= ( const int &x ){ this -> x = ( 1ll * x % mod * this -> x ) % mod; return *this; }
	Modular & operator /= ( const int &x ){ return *this *= inv( Modular( x ) ); }
 
	friend bool operator < ( Modular &a, Modular &b ) { return a.x < b.x; }
	friend bool operator == ( Modular &a, Modular &b ) { return a.x == b.x; }
	friend bool operator != ( Modular &a, Modular &b ) { return a.x != b.x; }
 
	friend Modular operator + ( Modular a, Modular b ){ return a += b; }
	friend Modular operator - ( Modular a, Modular b ){ return a -= b; }
	friend Modular operator * ( Modular a, Modular b ){ return a *= b; }
	friend Modular operator / ( Modular a, Modular b ){ return a /= b; }
 
	friend Modular inv( Modular m ){ return pow( m, mod - 2 ); }
	friend Modular pow( Modular m, long long n ){ Modular res( 1 ); while( n ){ if( n & 1 ) res *= m; m *= m; n >>= 1; } return res; }
	friend Modular mul( Modular m, long long n ){ Modular res; while( n ){ if( n & 1 ) res += m; m += m; n >>= 1; } return res; }
 
	friend ostream & operator << ( ostream &os, Modular m ){ return os << m.x; }
	friend istream & operator >> ( istream &is, Modular m ){ return is >> m.x; }
};