
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
#define INF INT_MAX

// Template ends, coding starts

#define mx 100010

int ara[mx];
pair <int, int> seg[4*mx];

void build(int nd, int st, int ed)
{
    if(st > ed)
        return;
    if(st == ed) {
        seg[nd] = make_pair(ara[st], ara[st]);
        return;
    }

    int mid = (st+ed)/2;
    build(2*nd, st, mid);
    build(2*nd+1, mid+1, ed);
    seg[nd] = make_pair(max(seg[2*nd].first, seg[2*nd+1].first), min(seg[2*nd].second, seg[2*nd+1].second));
    return;
}

pair <int, int> query(int nd, int st, int ed, int i, int j)
{
    if(j < st || i > ed) return make_pair(-1, INF);
    if(i <= st && j >= ed) return seg[nd];

    int mid = (st+ed)/2;
    pair <int, int> left = query(2*nd, st, mid, i, j);
    pair <int, int> right = query(2*nd+1, mid+1, ed, i, j);

    return make_pair(max(left.first, right.first), min(left.second, right.second));
}

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

    int t, cs = 1;
    scanf("%d", &t);

    while(t--) {
        int n, a;
        scanf("%d %d", &n, &a);
        for(int i = 0; i < n; i++) {
            scanf("%d", &ara[i]);
        }

        build(1, 0, n-1);

        int ans = 0, i = 0, j = 0;
        while(j < n) {
//            int low = i+ans;
//            int high = n-1;
//            if(low > high) break;
//            while(low <= high) {
//                int mid = (high+low)/2;
//                pair <int, int> tmp = query(1, 0, n-1, i, mid);
//                int x = tmp.first;
//                int m = tmp.second;
//                if(m+a >= x) {
//                    if(mid-i+1 > ans) ans = mid-i+1;
//                    low = mid+1;
//                }
//                else {
//                    high = mid-1;
//                }
//            }
            pair <int, int> tmp = query(1, 0, n-1, i, j);
            int x = tmp.first;
            int m = tmp.second;
//            cout << x << ' ' << m << endl;
            if(m+a >= x) {
                ans = max(ans, j-i+1);
                j++;
            }
            else i++;
        }

        printf("Case #%d: %d\n", cs++, ans);
    }

    return 0;
}
