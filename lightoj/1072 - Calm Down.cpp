#include <stdio.h>

int main()
{
    double pi = acos( -1 );
    int t, i, n;
    double R, p;

    scanf( "%d", &t );
    for( i = 1; i <= t; i++ ) {
        scanf( "%lf %d", &R, &n );
        p = sin( pi / n );
        printf( "Case %d: %lf\n", i, R*p/(1+p) );
    }

    return 0;
}
