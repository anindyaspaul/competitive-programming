#include <stdio.h>

unsigned findDig( unsigned x );

int main()
{
    unsigned n, i, j, t, dig_n, dig_x;

    scanf( "%u", &t );
    for( j = 1; j <= t; j++ ) {

        scanf( "%u", &n );

        dig_n = findDig( n );

        printf( "Case %u: %u\n", j, dig_n );

    }

    return 0;
}

unsigned findDig( unsigned x )
{
    unsigned i, j, coun = 0;
    unsigned pres = x, mask, y;

    for( i = 1 ; i <= 32; i++ ) {
        if( x & 1 ) {
            coun++;
            y = x >> 1;
            if( !( y & 1 ) ) {
                break;
            }
        }
        x >>= 1;
    }

    x = pres;
    mask = 1 << ( i );
    x = x | mask;
    while( i-- ) {
        mask >>= 1;
        x = x & ~mask;
    }
    j = 1;
    while( --coun ) {
        x = x | j;
        j <<= 1;
    }

    return x;
}
