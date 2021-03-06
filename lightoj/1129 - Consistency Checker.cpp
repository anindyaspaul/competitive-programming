/ Program  :
// Author   : Anindya Sundar Paul
// Algo     : Trie / Data Structure
// Verdict  :

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

#define EPS 1e-9
#define INF 1000000000
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

// Template ends, coding starts

class Node {
public:
    Node *next[10];

    Node()
    {
        for(int i = 0; i < 10; i++)
            next[i] = NULL;
    }
};

Node *root;
vector <string> dic;

void insert(string s)
{
    Node *cur = root;
    for(int i = 0; i < s.size(); i++) {
        int pos = s[i] - '0';
        if(cur->next[pos] == NULL)
            cur->next[pos] = new Node();
        cur = cur->next[pos];
    }
    return;
}

bool find(string s)
{
    Node *cur = root;
    int i = 0;
    for( ; i < s.size(); i++) {
        int pos = s[i] - '0';
        if(cur->next[pos] == NULL)
            break;
        cur = cur->next[pos];
    }

    if(i < s.size()) return true;
    else {
        for(int j = 0; j < 10; j++) {
            if(cur->next[j] != NULL) return false;
        }
        return true;
    }
}

void del(Node *s)
{
    if(!s) return;
    for(int i = 0; i < 10; i++) {
        del(s->next[i]);
    }
    delete s;
    return;
}

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

    int n, t, cs = 1;

    scani(t);
    while(t--) {

        root = new Node();
        scani(n);
        dic.clear();
        string s;
        for(int i = 0; i < n; i++) {
            cin >> s;
            dic.PB(s);
            insert(s);
        }

        bool out = true;
        for(int i = 0; i < n; i++) {
            out = out && find(dic[i]);
        }

        printf("Case %d: ", cs++);
        if(out) puts("YES");
        else puts("NO");

        del(root);
    }

    return 0;
}
