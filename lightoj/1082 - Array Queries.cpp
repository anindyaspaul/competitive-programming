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

#define mx 100001

int ara[mx];
int tree[3*mx];

void init( int node, int start, int fin )
{
    if( start == fin ) {
        tree[node] = ara[start];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = ( start + fin ) / 2;
    init( left, start, mid );
    init( right, mid+1, fin );
    tree[node] = min( tree[left], tree[right] );
    return;
}

int query( int node, int start, int fin, int qFrom, int qTo )
{
    if( start > qTo || fin < qFrom ) return INF;
    if( start >= qFrom && fin <= qTo ) return tree[node];
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = ( start + fin ) / 2;
    int ret1 = query( left, start, mid, qFrom, qTo );
    int ret2 = query( right, mid+1, fin, qFrom, qTo );
    return min( ret1, ret2 );
}

int main()
{
    int t, cs = 1;
    int n, q, start, fin, val;

    scanf( "%d", &t );
    while( t-- ) {

        scanf( "%d %d", &n, &q );
        for( int i = 1; i <= n; i++ ) {
            scanf( "%d", &ara[i] );
        }

        init( 1, 1, n );

//        for( int i = 1; i <= 2*n+1; i++ ) {
//            cout << "Node = " << i << " val = " << tree[i] << endl;
//        }

        printf( "Case %d:\n", cs++ );
        for( int i = 1; i <= q; i++ ) {
            scanf( "%d %d", &start, &fin );
            printf( "%d\n", query( 1, 1, n, start, fin ) );
        }
    }

    return 0;
}
