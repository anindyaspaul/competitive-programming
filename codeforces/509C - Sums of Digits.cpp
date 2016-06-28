
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
#define pii pair<int, int>
#define pll pair<LL, LL>

#define ndl ( '\n' )

#define what_is(x) cerr << #x << " = " << x << endl;

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
template <class T> inline T setBit( T n, T pos ) { return n = n | ((T)1<<pos); }
template <class T> inline T resetBit( T n, T pos ) { return n = n & ~((T)1<<pos); }
template <class T> inline bool checkBit( T n, T pos ) { return n & ((T)1<<pos); }

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
template <class T> inline T bigmod(T b, T p, T m) { if(p == 0) return 1;
	if(p%2 == 1) return ((b%m) * (bigmod(b, p-1, m)%m))%m;
	else { T tmp = bigmod(b, p/2, m)%m; return (tmp*tmp)%m; } }

#define EPS 1e-9
#define INF 1000000000

// Template ends, coding starts

#define MX 400

int b[MX];
int a[MX][MX];

void print(int r)
{
    int i = 0;
    while(a[r][i] == 0) i++;
    while(i < MX) {
        cout << a[r][i];
        i++;
    }
    cout << endl;
}

int cursum(int pos)
{
    int ret = 0;
    for(int i = 0; i < MX; i++) {
        ret += a[pos][i];
    }
    return ret;
}

void build(int pos)
{
    for(int i = 0; i < MX; i++) {
        a[pos][i] = a[pos-1][i];
    }
    for(int i = MX-1; i >= 0; i--) {
        if(a[pos][i] == 9) a[pos][i] = 0;
        else {
            a[pos][i]++;
            break;
        }
    }
    int i = MX-1;
    while(cursum(pos) > b[pos]) {
        a[pos][i--] = 0;
        while(a[pos][i] == 9) {
            a[pos][i] = 0;
            i--;
        }
        a[pos][i]++;
    }
    while(cursum(pos) + 9*(MX-1-i) < b[pos]) {
        while(a[pos][i] == 9) {
            a[pos][i] = 0;
            i--;
        }
        a[pos][i]++;
    }
    int add = b[pos] - cursum(pos);
    i = MX-1;
    while(add > 9) {
        a[pos][i] = 9;
        add -= 9;
        i--;
    }
    if(add > 0) a[pos][i] = add;
}

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

    int n;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for(int i = MX-1; b[0] > 0; i--) {
        int dig = 9;
        while(b[0] < dig) dig--;
        a[0][i] = dig;
        b[0] -= dig;
    }

    print(0);
    for(int i = 1; i < n; i++) {
        build(i);
        print(i);
    }

    return 0;
}
