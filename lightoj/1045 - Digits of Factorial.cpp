#include <stdio.h>
#include <math.h>

double ara[1000000];

int main()
{
    int t, i, j, n, base;
    double sum, res;

    sum = 0;
    for( j = 1; j <= 1000000; j++ ) {
        sum += log( j );
        ara[j] = sum;
    }

    scanf( "%d", &t );
    for( i = 1; i<= t; i++ ) {
        scanf( "%d %d", &n, &base );
        if( n == 0 ) {
            printf( "Case %d: 1\n", i );
            continue;
        }

        res = ara[n] / log( base );
        res = ceil( res );
        printf( "Case %d: %.0lf\n", i, res );
    }

    return 0;
}
