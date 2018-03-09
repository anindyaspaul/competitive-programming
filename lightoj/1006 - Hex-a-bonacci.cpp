#include <stdio.h>
#include <memory.h>

unsigned long long a, b, c, d, e, f;
unsigned long long dp[100000];

unsigned long long fn( unsigned long long n );

int main()
{
    unsigned long long n, caseno = 0, cases;


    scanf( "%llu", &cases );
    while( cases-- ) {
        memset( dp, -1, 100000 );
        scanf( "%llu %llu %llu %llu %llu %llu %llu", &a, &b, &c, &d, &e, &f, &n );
        printf( "Case %llu: %llu\n", ++caseno, fn(n) );
    }

    return 0;
}

unsigned long long fn( unsigned long long n )
{
    unsigned long long i;

    if( dp[n] != -1 ) return dp[n];

    dp[0] = a;
    dp[1] = b;
    dp[2] = c;
    dp[3] = d;
    dp[4] = e;
    dp[5] = f;

    for( i = 6; i <= n; i++ ) {
        dp[i] = ( dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6] ) % 10000007;
    }
    return dp[n] % 10000007;
}
