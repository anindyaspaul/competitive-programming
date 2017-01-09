#include <stdio.h>
#include <math.h>

int main()
{
    int T, i;
    double r, pi, area;

    scanf("%d", &T);
    pi = 2 * acos(0.0);
    for (i=1; i<=T; i++)
    {
        scanf("%lf", &r);
        area = 4*r*r - pi*r*r;
        printf("Case %d: %0.2f\n", i, area);
    }

    return 0;
}
