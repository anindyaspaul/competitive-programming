
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

int cnt[6000];

bool ca(int a, int b) { return a < b; }
bool cd(int a, int b) { return a > b; }

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

    int n;
    cin >> n;

    vector <int> vc;
    vc.clear();
    MEM(cnt, 0);

    int mx = -1;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mx = max(x, mx);
        vc.PB(x);
    }

    cnt[mx] = 1;
    vector <int> out1, out2;
    out1.clear();
    out2.clear();
    out2.PB(mx);

    for(int i = 0; i < n; i++) {
        int x = vc[i];
        if(x == mx);
        else if(cnt[x] == 0) {
            out2.PB(x);
            cnt[x]++;
        }
        else if(cnt[x] == 1) {
            out1.PB(x);
            cnt[x]++;
        }
    }

    sort(out1.begin(), out1.end(), ca);
    sort(out2.begin(), out2.end(), cd);

    bool f = false;
    cout << out1.size()+out2.size() << endl;
    for(int i = 0; i < out1.size(); i++) {
        if(!i) cout << out1[i];
        else cout << ' ' << out1[i];
        f = true;
    }
    for(int i = 0; i < out2.size(); i++) {
        if(!i && !f) cout << out2[i];
        else cout << ' ' << out2[i];
    }
    cout << endl;

    return 0;
}
