
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

#define EPS 1e-9
#define INF 1000000000

// Template ends, coding starts

#define pii pair<int, int>
#define piii pair <pii, int>

int r, c;
char grid[12][12];
bool visit[12][12];

bool isok(int i, int j)
{
    if(i < 0 || j < 0 || i >= r || j >= c) return false;
    if(visit[i][j]) return false;
    return true;
}

int bfs(int sr, int sc, int fr, int fc, int w)
{
    int dr[] = {1, 1, 2, 2, -1, -1, -2, -2};
    int dc[] = {2, -2, 1, -1, 2, -2, 1, -1};

    MEM(visit, 0);
    queue <piii> q;
    q.push(piii(pii(sr, sc), 0));
    visit[sr][sc] = true;

    while(!q.empty()) {
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int lev = q.front().second;
        q.pop();

        if(cr == fr && cc == fc) {
            if(lev == 0) return 0;
            else return lev%w == 0 ? lev/w : lev/w + 1;
        }

        for(int i = 0; i < 8; i++) {
            if(isok(cr+dr[i], cc+dc[i])) {
                visit[cr+dr[i]][cc+dc[i]] = true;
                q.push(piii(pii(cr+dr[i], cc+dc[i]), lev+1));
            }
        }
    }

    return INF;
}

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

    ios_base::sync_with_stdio(false);

    int t, cs = 1;

    cin >> t;
    while(t--) {

        vector < pii > src;

        cin >> r >> c;
        for(int i = 0; i < r; i++) {
            cin >> grid[i];
            for(int j = 0; j < c; j++) {
                if(grid[i][j] != '.') {
                    src.PB(pii(i, j));
                }
            }
        }

        vector <int> out;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                int sum = 0;
                for(int k = 0; k < src.size(); k++) {
                    int ret = bfs(src[k].first, src[k].second, i, j,
                                  grid[src[k].first][src[k].second]-'0');
                    if(ret == INF) {
                        sum = INF;
                        break;
                    }
                    else sum += ret;
                }
                out.PB(sum);
            }
        }

        sort(out.begin(), out.end());

        cout << "Case " << cs++ << ": ";
        if(out[0] == INF || src.size() == 0) cout << "-1" << ndl;
        else cout << out[0] << ndl;
    }

    return 0;
}
