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

#define psi pair<string, int>

set <string> restricted;
bool visit[26][26][26];

int bfs(string start, string fin)
{
    if(restricted.find(start) != restricted.end()) return -1;
    if(restricted.find(fin) != restricted.end()) return -1;

    queue < psi > q;
    q.push(psi(start, 0));
    MEM(visit, 0);
    visit[start[0]-'a'][start[1]-'a'][start[2]-'a'] = true;

    while(!q.empty()) {
        string u = q.front().first;
        int level = q.front().second;
        q.pop();
        if(u.compare(fin) == 0) return level;

//        debug(u);

        for(int i = 0; i < 3; i++) {
            string tmp = u;
            tmp[i] = tmp[i] + 1;
            if(tmp[i] > 'z') tmp[i] = 'a';
            if(!visit[tmp[0]-'a'][tmp[1]-'a'][tmp[2]-'a'] &&
                    restricted.find(tmp) == restricted.end()) {
                q.push(psi(tmp, level+1));
                visit[tmp[0]-'a'][tmp[1]-'a'][tmp[2]-'a'] = true;
            }

            tmp = u;
            tmp[i] = tmp[i] - 1;
            if(tmp[i] < 'a') tmp[i] = 'z';
            if(!visit[tmp[0]-'a'][tmp[1]-'a'][tmp[2]-'a'] &&
                    restricted.find(tmp) == restricted.end()) {
                q.push(psi(tmp, level+1));
                visit[tmp[0]-'a'][tmp[1]-'a'][tmp[2]-'a'] = true;
            }
        }
    }

    return -1;
}

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

    ios_base::sync_with_stdio(false);

    int t, cs = 1, n;
    string start, fin, a, b, c;

    cin >> t;
    while(t--) {

        restricted.clear();

        cin >> start >> fin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a >> b >> c;
            string temp = "abc";
            for(int j = 0; j < a.size(); j++) {
                for(int k = 0; k < b.size(); k++) {
                    for(int l = 0; l < c.size(); l++) {
                        temp[0] = a[j];
                        temp[1] = b[k];
                        temp[2] = c[l];
                        restricted.insert(temp);
                    }
                }
            }
        }

        int out = bfs(start, fin);

        cout << "Case " << cs++ << ": " << out << ndl;
    }

    return 0;
}
