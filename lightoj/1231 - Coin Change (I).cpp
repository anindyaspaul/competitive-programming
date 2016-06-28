#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

#include <map>
#include <queue>
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>

using namespace std;

#define EPS 1e-9
#define INF 1e10
#define PI acos( -1 )
#define RADIAN PI / 180

#define MEM( x, y ) memset( x, y, sizeof( x ) )

typedef long long LL;
typedef unsigned long long ULL;

/// Template ends, coding starts

#define MOD 100000007

LL n, coin[51], times[51];
LL dp[51][1001];

LL totalChange( LL i, LL now );

int main()
{
    LL i, t, make;

    cin >> t;

    for( i = 1; i <= t; i++ ) {

        MEM( dp, -1 );

        cin >> n >> make;
        for( LL j = 0; j < n; j++ )
            cin >> coin[j];
        for( LL j = 0; j < n; j++ )
            cin >> times[j];

        cout << "Case " << i << ": " << totalChange( 0, make ) << endl;
    }

    return 0;
}

LL totalChange( LL i, LL now )
{
    if( i >= n ) {
        if( now == 0 )
            return 1;
        else
            return 0;
    }

    if( dp[i][now] != -1 )
        return dp[i][now];

    LL ret = 0;
    for( LL take = 1; take <= times[i]; take++ ) {
        if( now - coin[i]*take >= 0 )
            ret += totalChange( i+1, now - coin[i]*take ) % MOD;
        else
            break;
    }
    ret += totalChange( i+1, now ) % MOD;

    dp[i][now] = ret % MOD;

    return dp[i][now];
}
