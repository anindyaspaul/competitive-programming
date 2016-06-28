#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    long long n1, n2, len;
    char number[15], tmp1[15], tmp2[15];

    gets( number );

    if( number[0] != '-' ) puts( number );
    else {
        if( number[1] == '0' && number[2] == '\0' ) puts( "0" );
        else {
            len = strlen( number );
            strcpy( tmp1, number );
            strcpy( &tmp1[len-2], &tmp1[len-1] );
            strcpy( tmp2, number );
            tmp2[len-1] = '\0';

            n1 = atol( tmp1 );
            n2 = atol( tmp2 );

            printf( "%lld\n", n1 >= n2 ? n1 : n2 );
        }
    }

    return 0;
}
