
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
#define INF INT_MAX
#define PI 3.14159265358979323846264338327950
#define RADIAN PI / 180

#define MEM( x, y ) memset( x, y, sizeof( x ) )
#define READ( file ) freopen( file, "r", stdin )
#define WRITE( file ) freopen( file, "w", stdout )

#define PB( x ) push_back( x )
#define PF( x ) push_front( x )

#define ASORT( ptr, n, type ) qsort( ptr, n, sizeof( type ), compareA )
#define DSORT( ptr, n, type ) qsort( ptr, n, sizeof( type ), compareD )

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
int compareA( const void * a, const void * b) { return *( int * ) a - *( int * ) b; }
int compareD( const void * a, const void * b) { return *( LL * ) b - *( LL * ) a; }

// Template ends, coding starts

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

    int n, m, i, ara[50], diff = INF;

    cin >> n >> m;
    for( i = 0; i < m; i++ ) cin >> ara[i];
    ASORT( ara, m, int );

    for( i = 0; i <= m-n; i++ ) {
        if( ara[i+n-1] - ara[i] < diff )
            diff = ara[i+n-1] - ara[i];
    }

    cout << diff << endl;

    return 0;
}
