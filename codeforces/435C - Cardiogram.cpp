
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

#define pii pair<int, int>
#define mx 1010

char grid[mx][mx];

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

    int n, x;
    vector <int> vc, cumx, cumy;
    vector < pii > co;

    while(cin >> n) {
        vc.clear();
        cumx.clear();
        cumy.clear();
        co.PB( pii(0,0) );
        for(int i = 0; i < n; i++) {
            cin >> x;
            vc.PB(x);

            if(!i) {
                cumx.PB(0);
                cumy.PB(0);
            }

            cumx.PB(cumx[i] + x);

            if(i&1) x = -x;
            cumy.PB(cumy[i] + x);
        }

        int ht = -1;
        int mxy = -1;
        for(int i = 0; i < cumy.size(); i++) {
            mxy = max(mxy, cumy[i]);
            for(int j = i+1; j < cumy.size(); j++) {
                ht = max(ht, abs(cumy[i]-cumy[j]));
            }
        }

        for(int i = 0; i < cumy.size(); i++) {
            cumy[i] = mxy - cumy[i];
        }

//        for(int i = 0; i < cumx.size(); i++)
//          cout << cumy[i] << ' ';
//        cout << endl;


        int i = cumy[0];
        int j = cumx[0];

        for(int it = 0; it < cumy.size()-1; it++) {
            if(it&1) {
                i++;
                int tmp = abs(cumy[it]-cumy[it+1]);
                while(tmp--) {
                    for(int k = 0; k < ht; k++) {
                        if(k == i) grid[k][j] = '\\';
                        else grid[k][j] = ' ';
                        grid[k][j+1] = 0;
                    }
                    i++;
                    j++;
                }
            }
            else {
                i--;
                int tmp = abs(cumy[it]-cumy[it+1]);
                while(tmp--) {
                    for(int k = 0; k < ht; k++) {
                        if(k == i) grid[k][j] = '/';
                        else grid[k][j] = ' ';
                        grid[k][j+1] = 0;
                    }
                    i--;
                    j++;
                }
            }
        }

        for(int i = 0; i < ht; i++)
            puts(grid[i]);


//        for(int i = 0; i < cumx.size(); i++)
//            cout << cumx[i] << ' ';
//        cout << endl;
//        for(int i = 0; i < cumx.size(); i++)
//          cout << cumy[i] << ' ';
    }

    return 0;
}
