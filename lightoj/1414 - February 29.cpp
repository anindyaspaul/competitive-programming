#include <stdio.h>
#include <string.h>

int main()
{
    int i, t, year1, year2, day1, day2, month1, month2, count;
    char m1[10], m2[10];

    scanf( "%d", &t );
    for( i = 1; i <= t; i++ ) {

        scanf( "%s %d, %d", m1, &day1, &year1 );
        scanf( "%s %d, %d", m2, &day2, &year2 );

        month1 = month2 = 0;
        if( !strcmp( m1, "January" ) ) month1 = 1;
        else if( !strcmp( m1, "February" ) ) month1 = 2;
        if( !strcmp( m2, "January" ) ) month2 = 1;
        else if( !strcmp( m2, "February" ) ) month2 = 2;

        if( month1 ) {
            if( ( year1 % 4 == 0 && year1 % 100 != 0 ) || year1 % 400 == 0 )
                year1--;
        }

        if( month2 == 1 || ( month2 == 2 && day2 < 29) )
            year2--;

        count = 0;

        count += year2 / 4;
        count -= year2 / 100;
        count += year2 / 400;
        count -= year1 / 4;
        count += year1 / 100;
        count -= year1 / 400;

        printf( "Case %d: %d\n", i, count );
    }


    return 0;
}
