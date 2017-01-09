#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <bitset>

#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

#define EPS 1e-9
#define INF 1e10
#define PI 3.14159265358979323846264338327950
#define RADIAN PI / 180

#define MEM( x, y ) memset( x, y, sizeof( x ) )
#define READ( file ) freopen( file, "r", stdin )
#define WRITE( file ) freopen( file, "w", stdout )

typedef long long LL;
typedef unsigned long long ULL;

/// Template ends, coding starts

LL mat[202][102], dp[202][102], n;

LL banana( LL i, LL j );

int main()
{
    LL t, cs;

    cin >> t;
    for( cs = 1; cs <= t; cs++ ) {

        MEM( mat, -1 );
        MEM( dp, -1 );
        cin >> n;
        for( LL i = 1; i <= n; i++ )
            for( LL j = 1; j <= i; j++ )
                cin >> mat[i][j];
        for( LL x = 1, i = n+1; i <= 2*n-1 ; i++, x++ )
            for( LL j = 1; j <= n-x; j++ )
                cin >> mat[i][j];

        cout << "Case " << cs << ": " << banana( 1, 1 ) << endl;
    }

    return 0;
}

LL banana( LL i, LL j )
{
    if( mat[i][j] == -1 ) return 0;

    if( dp[i][j] != -1 ) return dp[i][j];

    LL ret = -1;
    ret = max( ret, banana( i+1, j ) + mat[i][j] );
    if( i < n ) ret = max( ret, banana( i+1, j+1 ) + mat[i][j] );
    else ret = max( ret, banana( i+1, j-1 ) + mat[i][j] );

    dp[i][j] = ret;

    return dp[i][j];
}
