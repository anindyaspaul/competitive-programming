#include <stdio.h>
#include <math.h>

int main()
{
    int t, i;
    double r1, r2, r3, a, b, c, A, B, C, temp;
    double area, area1, area2, area3, tri_area;

    scanf( "%d", &t );
    for( i = 1; i <= t; i++ ) {
        scanf( "%lf %lf %lf", &r1, &r2, &r3 );
        c = r1 + r2;
        b = r1 + r3;
        a = r2 + r3;
        temp = (b*b + c*c - a*a) / (2*b*c);
        A = acos( temp );
        temp = (a*a + c*c - b*b) / (2*a*c);
        B = acos( temp );
        temp = (b*b + a*a - c*c) / (2*b*a);
        C = acos( temp );
        area1 = A / 2 * r1*r1;
        area2 = B / 2 * r2*r2;
        area3 = C / 2 * r3*r3;
        tri_area = 0.5 * b * c * sin( A );
        area = tri_area - area1 - area2 - area3;

        printf( "Case %d: %lf\n", i, area );
    }

    return 0;
}
