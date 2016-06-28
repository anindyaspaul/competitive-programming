
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

#define mx 5010

LL ara[mx], cum[mx];

LL nd[mx];

LL sz, m;
LL dp[mx][mx];
bool check[mx][mx];

LL func(int i, int j)
{
    if(j <= 0) return 0;
    if(i >= sz) return 0;
    if(check[i][j] == true) return dp[i][j];

    LL ret1 = nd[i] + func(i+m, j-1);
    LL ret2 = func(i+1, j);

    check[i][j] = true;
    return dp[i][j] = max(ret1, ret2);
}

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

    LL n, k;

    cin >> n >> m >> k;

    cum[0] = 0;
    for(LL i = 1; i <= n; i++) {

        cin >> ara[i];
        cum[i] = cum[i-1] + ara[i];
    }

    LL j = 0;
    for(LL i = m; i <= n; i++) {
        nd[j++] = cum[i] - cum[i-m];
    }
    sz = j;

    LL out = func(0, k);

    cout << out << endl;

    return 0;
}
