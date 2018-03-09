
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

#define EPS 1e-9
#define INF 2000000000
#define PI 3.14159265358979323846264338327950
#define RADIAN PI / 180

#define MEM( x, y ) memset( x, y, sizeof( x ) )
#define READ( file ) freopen( file, "r", stdin )
#define WRITE( file ) freopen( file, "w", stdout )

#define PB( x ) push_back( x )
#define PF( x ) push_front( x )

#define ASORT( ptr, n, type ) qsort( ptr, n, sizeof( type ), compareA )
#define DSORT( ptr, n, type ) qsort( ptr, n, sizeof( type ), compareD )

//#define scanI( x ) scanf( "%d", &x )
//#define scanL( x ) scanf( "%lld", &x )
//#define scanD( x ) scanf( "%lf", &x )
//#define scanS( x ) scanf( "%s", x )
//#define scanII( x, y ) scanf( "%d %d", &x, &y )
//#define scanLL( x, y ) scanf( "%lld %lld", &x, &y )
//#define scanDD( x, y ) scanf( "%lf %lf", &x, &y )
//#define printI( x ) printf( "%d\n", x )
//#define printL( x ) printf( "%lld\n", x )
//#define printD( x ) printf( "%lf\n", x )
//#define printII( x, y ) printf( "%d %d\n", x, y )
//#define printLL( x, y ) printf( "%lld %lld\n", x, y )
//#define printDD( x, y ) printf( "%lf %lf\n", x, y )

typedef long long LL;
typedef unsigned long long ULL;

// Powers
template <class T> inline T sqr( T x ) { return x*x; }
template <class T> inline T cube( T x ) { return x*x*x; }
template <class T> inline T quad( T x ) { return x*x*x*x; }

// Bit Manipulation
template <class T> inline T setBit( T n, T pos ) { return n = n | ( 1 << pos ); }
template <class T> inline T resetBit( T n, T pos ) { return n = n & ~( 1 << pos ); }
template <class T> inline bool checkBit( T n, T pos ) { return n & ( 1 << pos ); }

// GCD, LCM
template <class T> inline T GCD( T a, T b ) { if( a < 0 ) return GCD( -a , b );
    if( b < 0 ) return GCD( a, -b ); return ( b == 0 ) ? a : GCD( b, a%b ); }
template <class T> inline T LCM( T a, T b ) { if( a < 0 ) return LCM( -a, b );
    if( b < 0 ) return LCM( a, -b ); return a * ( b / GCD( a, b ) ); }

// Prime
template <class T> inline bool isPrime( T n ) { if( n <= 1 ) return false;
    for( T i = 2; i*i <= n; i++ ) if( n % i == 0 ) return false; return true; }

// Comparison functions for qsort - types to be adjusted
int asc( const void * a, const void * b) { return *( LL * ) a - *( LL * ) b; }
int dsc( const void * a, const void * b) { return *( LL * ) b - *( LL * ) a; }

// Operator overload
// bool operator < ( const className& c ) const { return w > c.w; }

// Template ends, coding starts

int main()
{
    int n, k;

    cin >> n >> k;

    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            if( j > 0 ) cout << ' ';
            if( i == j ) cout << k;
            else cout << 0;
        }
        cout << endl;
    }

    return 0;
}
