

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
int asc( const void * a, const void * b) { return *( LL * ) a - *( LL * ) b; }
int dsc( const void * a, const void * b) { return *( LL * ) b - *( LL * ) a; }

// Template ends, coding starts

class Node {
public:
    double x, y;
    bool operator < ( const Node &n ) const {
        if( this->x != n.x ) return this->x < n.x;
        else return this->y < n.y;
    }
};

Node node[12];

int val;
int g[12][12];
int visit[12];
int color[12];

map <Node, int> m;

bool findCol( int src, int col )
{
    int i, j;
    for( i = 0; i < val; i++ ) {
        if( g[src][i] == 1 && color[i] == col )
            return true;
    }
    return false;
}

void bfs( int src )
{
    int c, i, f, j;
    queue <int> q;
    q.push( src );
    color[src] = 0;
    visit[src] = 1;
    while( !q.empty() ) {
        f = q.front();
        q.pop();
        c = color[f];
        for( i = 0; i < val; i++ ) {
            if( g[f][i] == 1 ) {
                if( !visit[i] ) {
                    visit[i] = 1;
                    for( j = 0; j < c; j++ ) {
                        if( !findCol( i, j ) ) {
                            color[i] = j;
                            break;
                        }
                    }
                    if( j == c ) color[i] = c + 1;
                    q.push( i );
                }
                else if( color[i] == c ) {
                    for( j = 0; j < c; j++ ) {
                        if( !findCol( i, j ) ) {
                            color[i] = j;
                            break;
                        }
                    }
                    if( j == c ) color[i] = c + 1;
                }
//                cout << "color of " << i << " = " << color[i] << endl;
            }
        }
    }
    return;
}

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

    int i, j, a, b;
    int n, ans, cs = 1;
    double xco, yco, dis;

    while( cin >> n ) {
        if( n == 0 ) return 0;

        val = 0;
        for( i = 0; i < n; i++ ) {
            cin >> xco >> yco;
            node[i].x = xco;
            node[i].y = yco;
            if( m.find( node[i] ) == m.end() ) m[node[i]] = val++;
//            cout << val << endl;
        }

//        for( i = 0; i < m.size(); i++ )
//            cout << i << ' ' << m[node[i]] << endl;

        MEM( g, 0 );
        for( i = 0; i < n; i++ ) {
            for( j = n-1; j > i; j-- ) {
                dis = sqr( node[i].x - node[j].x ) + sqr( node[i].y - node[j].y );
                if( dis <= 400 ) {
                    a = m[node[i]];
                    b = m[node[j]];
                    g[a][b] = 1;
                    g[b][a] = 1;
//                    cout << a << ' ' << b << endl;
                }
            }
        }

//        for( i = 0; i < val; i++ ) {
//            for( j = 0; j < val; j++ ) {
//                cout << g[i][j] << ' ';
//            }
//            cout << endl;
//        }

        MEM( visit, 0 );
        MEM( color, -1 );
        for( i = 0; i < val; i++ ) {
            if( !visit[i] )
                bfs( i );
        }
        ans = -1;
        for( i = 0; i < val; i++ ) {
            if( color[i] > ans )
                ans = color[i];
        }

        cout << "The towers in case " << cs++ << " can be covered in " << ans + 1 << " frequencies." << endl;

        m.clear();
    }

    return 0;
}
