
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

#define mx 2000010

int zcnt, ocnt;
bool unpossible;
int color[mx];
vector <int> graph[mx], cost[mx];

void dfs1(int u)
{
    for(int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        int w = cost[u][i];
        if(color[v] == -1) {
            if(w == 0) {
                color[v] = 0;
                dfs1(v);
            }
            else if(w == 2) {
                color[v] = 1;
                dfs1(v);
            }
            else {
                color[v] = 1-color[u];
                dfs1(v);
            }
        }
        else {
            if(w != 1) {
                if(color[u] != color[v])
                    unpossible = true;
            }
            else if(color[u] == color[v])
                unpossible = true;
        }
    }
}

void dfs2(int u)
{
    if(color[u] == 0) zcnt++;
    if(color[u] == 1) ocnt++;

    for(int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if(color[v] == -1) {
            color[v] = 1-color[u];
            dfs2(v);
        }
        else {
            if(color[u] == color[v])
                unpossible = true;
        }
    }
}

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

    int n, m;

    while(cin >> n >> m) {

        for(int i = 1; i <= n; i++) {
            graph[i].clear();
            cost[i].clear();
            color[i] = -1;
        }

        unpossible = false;
        while(m--) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].PB(v);
            graph[v].PB(u);
            cost[u].PB(w);
            cost[v].PB(w);
        }

        for(int u = 1; u <= n; u++) {
            if(color[u] != -1) continue;
            for(int j = 0; j < graph[u].size(); j++) {
                int w = cost[u][j];
                if(w != 1) {
                    color[u] = (w == 2) ? 1 : 0;
                    dfs1(u);
                    break;
                }
            }
        }

        int sum = 0;
        for(int i = 1; i <= n; i++) {
            if(color[i] != -1) sum += color[i];
        }

        for(int u = 1; u <= n; u++) {
            if(color[u] == -1) {
                color[u] = 0;
                zcnt = 0;
                ocnt = 0;
                dfs2(u);
                sum += min(zcnt, ocnt);
            }
        }

        if(unpossible) cout << "impossible" << endl;
        else cout << sum << endl;
    }

    return 0;
}
