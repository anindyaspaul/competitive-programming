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
#define scani( x ) scanf( "%d", &x )
#define scanl( x ) scanf( "%lld", &x )
#define scand( x ) scanf( "%lf", &x )
#define scans( x ) scanf( "%s", x )
#define scanii( x, y ) scanf( "%d %d", &x, &y )
#define scanll( x, y ) scanf( "%lld %lld", &x, &y )
#define scandd( x, y ) scanf( "%lf %lf", &x, &y )
#define printi( x ) printf( "%d\n", x )
#define printl( x ) printf( "%lld\n", x )
#define printd( x ) printf( "%lf\n", x )
#define printii( x, y ) printf( "%d %d\n", x, y )
#define printll( x, y ) printf( "%lld %lld\n", x, y )
#define printdd( x, y ) printf( "%lf %lf\n", x, y )

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

#define mx 20010

int n;
bool visit[mx];
bool color[mx];
vector <int> g[mx];
map <int, int> mp;

int bfs(int src)
{
    queue <int> q;
    visit[src] = true;
    int c0 = 0;
    int c1 = 1;
    color[src] = true;
    q.push(src);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if(!visit[v]) {
                visit[v] = true;
                q.push(v);
                if(color[u]) {
                    color[v] = false;
                    c0++;
                }
                else {
                    color[v] = true;
                    c1++;
                }
            }
        }
    }

    if(c0 > c1) return c0;
    else return c1;
}

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

    int t, cs = 1;

    cin >> t;
    while(t--) {

        mp.clear();
        n = 0;

        int m;
        cin >> m;
        while(m--) {

            int u, v;
            cin >> u >> v;
            if(mp.find(u) == mp.end()) mp[u] = n++;
            if(mp.find(v) == mp.end()) mp[v] = n++;
            u = mp[u];
            v = mp[v];
            g[u].PB(v);
            g[v].PB(u);
        }

        MEM(visit, 0);
        MEM(color, 0);
        int out = 0;
        for(int i = 0; i < n; i++) {
            if(!visit[i])
                out += bfs(i);
        }

        printf("Case %d: %d\n", cs++, out);

        for(int i = 0; i < n; i++)
            g[i].clear();
    }

    return 0;
}
