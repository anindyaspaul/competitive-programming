

// Author   : Anindya Sundar Paul
// Institute: CSE, University of Dhaka

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

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

    int n, x;

    while(cin >> n) {
        vector <int> vc;
        vc.clear();
        for(int i = 0; i < n; i++) {
            cin >> x;
            vc.PB(x);
        }

        sort(vc.begin(), vc.end());

        if(n == 1) {
            puts("-1");
            continue;
        }

        if(n == 2) {
            int diff = vc[1]-vc[0];
            if(diff == 0) {
                puts("1");
                cout << vc[0] << endl;
            }
            else if(diff%2 == 0) {
                puts("3");
                cout << vc[0]-diff << ' ' << (vc[1]+vc[0])/2
                    << ' ' << vc[1]+diff << endl;
            }
            else {
                puts("2");
                cout << vc[0]-diff << ' ' << vc[1]+diff << endl;
            }
            continue;
        }

        map <int, int> mp;
        mp.clear();
        vector <int> vd;
        vd.clear();

        int diffs = 0;
        int diffVal = 0;
        for(int i = 1; i < vc.size(); i++) {
            int d = vc[i] - vc[i-1];
            diffVal = d;
            if(mp.find(d) == mp.end()) {
                mp[d] = 1;
                diffs++;
                vd.PB(d);
            }
            else mp[d]++;
        }

        if(diffs == 1) {
            if(diffVal == 0) {
                puts("1");
                cout << vc[0] << endl;
            }
            else {
                puts("2");
                cout << vc[0]-diffVal << ' ' << vc[n-1]+diffVal << endl;
            }
        }
        else if(diffs == 2) {
            if(mp[vd[0]] != 1 && mp[vd[1]] != 1) {
                puts("0");
            }
            else {
                bool f = false;
                if(mp[vd[0]] == 1) {
                    for(int i = 1; i < n; i++) {
                        if(vc[i]-vc[i-1] == vd[0]) {
                            if(vd[1]+vd[1]==vd[0]) {
                                puts("1");
                                cout << vc[i]-vd[1] << endl;
                                f = true;
                                break;
                            }
                        }
                    }
                }
                if(mp[vd[1]] == 1 && !f) {
                    for(int i = 1; i < n; i++) {
                        if(vc[i]-vc[i-1] == vd[1]) {
                            if(vd[0]+vd[0]==vd[1]) {
                                puts("1");
                                cout << vc[i]-vd[0] << endl;
                                f = true;
                                break;
                            }
                        }
                    }
                }
                if(!f) puts("0");
            }
        }
        else {
            puts("0");
        }
    }

    return 0;
}
