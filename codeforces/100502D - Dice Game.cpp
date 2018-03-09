
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

#define mx 300

int cntema[mx], cntgun[mx];
double prbema[mx], prbgun[mx];

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

    int a, b, c, d;

    while(cin >> a >> b >> c >> d) {
        MEM(prbema, 0);
        MEM(prbgun, 0);

        for(int i = a; i <= b; i++) {
            for(int j = c; j <= d; j++) {
                prbgun[i+j] += (double)1/((b-a+1)*(d-c+1));
            }
        }

        cin >> a >> b >> c >> d;
        for(int i = a; i <= b; i++) {
            for(int j = c; j <= d; j++) {
                prbema[i+j] += (double)1/((b-a+1)*(d-c+1));
            }
        }

        double exgun = 0.0;
        double exema = 0.0;
        for(int i = 0; i < mx; i++) {
            exgun += (prbgun[i]*i);
        }
        for(int i = 0; i < mx; i++) {
            exema += (prbema[i]*i);
        }

//        printf("%0.16lf %0.16lf\n", exgun, exema);

        if(exgun+EPS < exema) cout << "Emma" << endl;
        else if(exgun > exema+EPS) cout << "Gunnar" << endl;
        else cout << "Tie" << endl;

//        printf("%0.16lf %0.16lf\n", exgun, exema);

    }

    return 0;
}
