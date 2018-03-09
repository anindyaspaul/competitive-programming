#include <stdio.h>
#include <math.h>

int main()
{
    int T, i;
    double a, b, c, d, s, tri_area, h, trap_area;


    scanf("%d", &T);
    for ( i=1; i<=T; i++ )
    {
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        s = (a - c + b + d)/2;
        tri_area =  sqrt( s*(s-a+c)*(s-b)*(s-d) );
        h = 2*tri_area/(a-c);
        trap_area = (a+c)*h/2;
        if ( trap_area<0 )
            printf("Case %d: %lf\n", i, -trap_area);
        else
            printf("Case %d: %lf\n", i, trap_area);
    }

    return 0;
}
