
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

//int dx[] = {0, 0, +1, -1};
//int dy[] = {+1, -1, 0, 0};

#define EPS 1e-9
#define INF 1000000000

// Template ends, coding starts

#define MX 1000010

int freq[MX];
int lft[MX];
int rgt[MX];

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );
    ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;

	int mx = 0;
	int l = 0;
	int r = 0;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;

		if(freq[x] == 0) {
			lft[x] = i;
			rgt[x] = i;
		}
		else {
			rgt[x] = i;
		}

		freq[x]++;

		if(freq[x] > mx) {
			mx = freq[x];
			l = lft[x];
			r = rgt[x];
		}
		else if(freq[x] == mx) {
			if((r-l) > (rgt[x]-lft[x])) {
				l = lft[x];
				r = rgt[x];
			}
		}
	}

	cout << l << " " << r << endl;

    return 0;
}
