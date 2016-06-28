#include <stdio.h>

int main()
{
    int t, i, j, n, p, q, count, weight, ara[1000];

    scanf( "%d", &t );
    for( i = 1; i <= t; i++ ) {
        scanf( "%d %d %d", &n, &p, &q );
        for( j = 0; j < n; j++ ) scanf( "%d", &ara[j] );

        count = 0;
        weight = 0;
        for( j = 0; (count <= p) && (weight <= q) && (j < n); j++ ) {
            weight += ara[j];
            count++;
        }

        if( (j == n) && (count <= p) && (weight <= q) ) count++;
        printf( "Case %d: %d\n", i, count-1 );
    }


    return 0;
}
