
#include <bits/stdc++.h>

using namespace std;

#ifdef __GNUC__
typedef long long LL;
typedef unsigned long long ULL;
#else
typedef __int64 LL;
typedef unsigned __int64 ULL;
#endif
typedef unsigned UI;

#define PI 3.14159265358979323846264338327950
#define RADIAN PI / 180

#define MEM( x, y ) memset( x, y, sizeof( x ) )
#define READ( file ) freopen( file, "r", stdin )
#define WRITE( file ) freopen( file, "w", stdout )

#define PB( x ) push_back( x )
#define PF( x ) push_front( x )

#define ndl ( '\n' )

// Debugs
template <class T> inline void debug( T x )
{ cout << "x = " << x << endl; }
template <class T1, class T2> inline void debug( T1 x, T2 y )
{ cout << "x = " << x << ", y = " << y << endl; }
template <class T1, class T2, class T3> inline void debug( T1 x, T2 y, T3 z )
{ cout << "x = " << x << ", y = " << y << ", z = " << z << endl; }

// Powers
template <class T> inline T sqr( T x ) { return x*x; }
template <class T> inline T cube( T x ) { return x*x*x; }
template <class T> inline T quad( T x ) { return x*x*x*x; }

// Bit Manipulation
template <class T> inline T setBit( T n, T pos ) { return n = n | (1<<pos); }
template <class T> inline T resetBit( T n, T pos ) { return n = n & ~(1<<pos); }
template <class T> inline bool checkBit( T n, T pos ) { return n & (1<<pos); }

// GCD, LCM
template <class T> inline T GCD( T a, T b ) { if( a < 0 ) return GCD( -a , b );
    if( b < 0 ) return GCD( a, -b ); return ( b == 0 ) ? a : GCD( b, a%b ); }
template <class T> inline T LCM( T a, T b ) { if( a < 0 ) return LCM( -a, b );
    if( b < 0 ) return LCM( a, -b ); return a * ( b / GCD( a, b ) ); }

// Prime
template <class T> inline bool isPrime( T n ) { if( n <= 1 ) return false;
    for( T i = 2; i*i <= n; i++ ) if( n % i == 0 ) return false; return true; }

// Various
template <class T> inline T abso( T x ) { return x >= 0 ? x : -x; }
template <class T> inline T mod( T n, T m ) { return ( n%m + m ) % m; }

#define EPS 1e-9
#define INF 2000000000

// Template ends, coding starts

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

	string s;
	vector <int> pos, out;

	cin >> s;
	int dif = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(') dif++;
		if(s[i] == ')') dif--;
		if(s[i] == '#') {
			s[i] = ')';
			pos.PB(i);
			dif--;
		}
	}

	for(int i = 0; i < pos.size(); i++) {
		if(i < pos.size()-1) out.PB(0);
		else out.PB(abs(dif));
	}

	dif = 0;
	bool flag = true;
	for(int i = 0, it = 0; flag && i < s.size(); i++) {
		if(s[i] == '(') dif++;
		if(s[i] == ')') dif--;
		if(i == pos[pos.size()-1]) dif -= out[out.size()-1];
		if(dif < 0) flag = false;
	}

	if(!flag) cout << "-1" << endl;
	else {
		for(int i = 0; i < out.size(); i++) {
			cout << out[i]+1 << endl;
		}
	}

    return 0;
}
