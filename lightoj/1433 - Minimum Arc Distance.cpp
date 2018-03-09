#include <stdio.h>
#include <math.h>

int main()
{
    int T, i, ox, oy, ax, ay, bx, by;
    double oa, ab, theta, s;

    scanf("%d", &T);
    for ( i=1; i<=T; i++)
    {
        scanf("%d %d %d %d %d %d", &ox, &oy, &ax, &ay, &bx, &by);
        oa = sqrt((ax-ox)*(ax-ox) + (ay-oy)*(ay-oy));
        ab = sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
        theta = asin(ab/(2*oa));
        printf("Case %d: %lf\n", i, 2*oa*theta);
    }

    return 0;
}
