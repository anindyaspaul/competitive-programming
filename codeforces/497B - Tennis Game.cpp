
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

#define EPS 1e-9
#define INF 2000000000

// Template ends, coding starts

#define mx 100010

int cum1[mx], cum2[mx];
vector <pair<int, int> > vc;

bool check(int n, int &s, int t)
{
	s = 0;
	int low1 = 1, high1 = n, low2 = 1, high2 = n, tmp1 = t, tmp2 = t;
	int low1bak = 1, low2bak = 1, s1 = 0, s2 = 0;

	while(true) {

		int pos1 = INF, pos2 = INF;

		while(low1 <= high1) {
			int mid = (low1+high1)/2;
			if(tmp1 < cum1[mid]) high1 = mid-1;
			else if(tmp1 == cum1[mid]) {
				pos1 = mid;
				high1 = mid-1;
			}
			else low1 = mid+1;
		}

		while(low2 <= high2) {
			int mid = (low2+high2)/2;
			if(tmp2 < cum2[mid]) high2 = mid-1;
			else if(tmp2 == cum2[mid]) {
				pos2 = mid;
				high2 = mid-1;
			}
			else low2 = mid+1;
		}

//		cout << t << ' ' << pos1 << ' ' << pos2 << endl;

		if(pos1 == pos2) return false;

		if(pos1 < pos2) {
			s1++;
			s = max(s, s1);
			if(pos1 == n && s1 != s2 && s != s2) return true;
			tmp1 = cum1[pos1] + t;
			tmp2 = cum2[pos1] + t;
			low1 = pos1 + 1;
			low1bak = low1;
			low2 = low1;
			high1 = high2 = n;
		}
		else {
			s2++;
			s = max(s, s2);
			if(pos2 == n && s1 != s2 && s != s1) return true;
			tmp2 = cum2[pos2] + t;
			tmp1 = cum1[pos2] + t;
			low2 = pos2 + 1;
			low2bak = low2;
			low1 = low2;
			high1 = high2 = n;
		}
	}
}

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

	ios_base::sync_with_stdio(false);

	int n, x;

	cin >> n;

	cum1[0] = cum2[0] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		cum1[i] = cum1[i-1];
		cum2[i] = cum2[i-1];
		if(x == 1) cum1[i]++;
		else cum2[i]++;
	}

	int s;
	for(int t = 1; t <= n; t++) {
		if(check(n, s, t)) {
			vc.PB(make_pair(s, t));
		}
	}

	sort(vc.begin(), vc.end());

	cout << vc.size() << endl;
	for(int i = 0; i < vc.size(); i++) {
		cout << vc[i].first << " " << vc[i].second << endl;
	}

    return 0;
}
