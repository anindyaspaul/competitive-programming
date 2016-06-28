
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

#define mx 100010
#define MOD 1000000007

int n;
bool visit[mx];
vector <int> cost;
vector <int> g[mx], inv[mx];
stack <int> st;
vector <int> out;
LL mini, outcost;
LL outnum;

void dfsg(int src)
{
    visit[src] = true;
    for(int i = 0; i < g[src].size(); i++) {
        int v = g[src][i];
        if(!visit[v])
            dfsg(v);
    }
    st.push(src);
}

void dfsinv(int src)
{
    visit[src] = true;
    for(int i = 0; i < inv[src].size(); i++) {
        int v = inv[src][i];
        if(!visit[v]) {
            dfsinv(v);
        }
    }

    out.PB(src);
    if(cost[src] < mini) mini = cost[src];
}

int findmini()
{
    int cnt = 0;
    for(int i = 0; i < out.size(); i++) {
        int u = out[i];
        if(cost[u] == mini) cnt++;
    }
    return cnt;
}

LL mul(LL a, LL b)
{
    LL ret = 0;
    while(b--) {
        ret += a;
        if(ret >= MOD)
            ret %= MOD;
    }
    return ret;
}

void kosaraju()
{
    MEM(visit, 0);
    for(int i = 1; i <= n; i++) {
        if(!visit[i])
            dfsg(i);
    }

    MEM(visit, 0);
    while(!st.empty()) {
        int u = st.top();
        st.pop();
        if(!visit[u]) {
            mini = INF;
            dfsinv(u);
            outcost += mini;
            int temp = findmini();
            outnum = mul(outnum, temp);
            outnum %= MOD;
            out.clear();
        }
    }
}

int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

    int m, x, u, v;
    while(cin >> n) {
        cost.clear();
        cost.PB(0);
        for(int i = 0; i < n; i++) {
            cin >> x;
            cost.PB(x);
            g[i+1].clear();
            inv[i+1].clear();
        }
        cin >> m;
        while(m--) {
            cin >> u >> v;
            g[u].PB(v);
            inv[v].PB(u);
        }

        outnum = 1;
        outcost = 0;
        kosaraju();

        cout << outcost << " " << outnum << endl;
    }

    return 0;
}
