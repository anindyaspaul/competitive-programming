
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <climits>

#include <string>
#include <complex>
#include <iomanip>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <bitset>

#include <new>
#include <limits>
#include <memory>
#include <locale>
#include <iterator>

#include <ctime>
#include <cwchar>
#include <cerrno>
#include <cfloat>
#include <clocale>
#include <ciso646>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwctype>

#include <ios>
#include <numeric>
#include <fstream>
#include <streambuf>

using namespace std;

#ifdef __GNUC__
typedef long long LL;
typedef unsigned long long ULL;
#else
typedef __int64 LL;
typedef unsigned __int64 ULL;
#endif
typedef unsigned UI;

#define EPS 1e-9
#define INF 2000000000
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

// Template ends, coding starts

vector <int> a, b;
vector <bool> ca, cb;

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

    int n;
    int x, y;
    cin >> n;

    for( int i = 0; i < n; i++ ) {
        cin >> x >> y;
        a.PB( x );
        b.PB( y );
        ca.PB( false );
        cb.PB( false );
    }

    int k = n/2;
    for( int i = 0; i < k; i++ ) {
        ca[i] = true;
        cb[i] = true;
    }
    if( k+k < n ) {
        if( a[k] <= b[k] ) ca[k] = true;
        else cb[k] = true;
    }

    int i = 0, j = 0, c = 0;
    while( c < n ) {
        if( a[i] <= b[j] ) {
            ca[i] = true;
            i++;
        }
        else {
            cb[j] = true;
            j++;
        }
        c++;
    }

    for( int i = 0; i < n; i++ ) {
        if( ca[i] ) putchar( '1' );
        else putchar( '0' );
    }
    puts( "" );

    for( int i = 0; i < n; i++ ) {
        if( cb[i] ) putchar( '1' );
        else putchar( '0' );
    }
    puts( "" );

    return 0;
}
