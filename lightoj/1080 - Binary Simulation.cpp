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

#define mx 100010

char str[mx];

class Node {
public:
    int val;
    int tog;

    Node()
    {
        val = 0;
        tog = 0;
    }
};

Node node[4*mx];

void build(int root, int st, int ed)
{
    if(st == ed) {
        node[root].val = str[st] - '0';
        node[root].tog = 0;
        return;
    }

    int mid = (st+ed)/2;
    build(2*root, st, mid);
    build(2*root+1, mid+1, ed);
    node[root].tog = 0;
    return;
}

void update(int root, int st, int ed, int i, int j)
{
    if(i > ed || j < st) return;

    if(i <= st && j >= ed) {
        node[root].tog = 1-node[root].tog;
        return;
    }

    int mid = (st+ed)/2;
    update(2*root, st, mid, i, j);
    update(2*root+1, mid+1, ed, i, j);
    return;
}

int query(int root, int st, int ed, int pos, int cnt)
{
    if(st == ed) {
        cnt += node[root].tog;
        if(cnt & 1) return 1-node[root].val;
        else return node[root].val;
    }

    int mid = (st+ed)/2;
    if(pos <= mid) return query(2*root, st, mid, pos, cnt+node[root].tog);
    else return query(2*root+1, mid+1, ed, pos, cnt+node[root].tog);
}

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

    int t, cs = 1;

    scani(t);
    while(t--) {

        scans(str);
        int len = strlen(str);

        build(1, 0, len-1);

        printf("Case %d:\n", cs++);

        int q;
        scani(q);
        while(q--) {
            getchar();
            char com;
            int a, b;
            scanf("%c", &com);
            if(com == 'I') {
                scanii(a, b);
                update(1, 0, len-1, a-1, b-1);
            }
            else {
                scani(a);
                int out = query(1, 0, len-1, a-1, false);
                printi(out);
            }
        }
    }

    return 0;
}
