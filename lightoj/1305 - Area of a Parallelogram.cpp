#include <stdio.h>
#include <math.h>

int main()
{
    int T, i, ax, ay, bx, by, cx, cy, dx, dy, area;

    scanf("%d", &T);
    for ( i=1; i<=T; i++ )
    {
        scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);
        dx = ax+cx-bx;
        dy = ay+cy-by;
        area = ((ax*(by-cy)+bx*(cy-dy)+cx*(dy-ay)+dx*(ay-by)) - (ay*(bx-cx)+by*(cx-dx)+cy*(dx-ax)+dy*(ax-bx)))/2;
        if (area<0)
            printf("Case %d: %d %d %d\n", i, dx, dy, -area);
        else
            printf("Case %d: %d %d %d\n", i, dx, dy, area);
    }

    return 0;
}
