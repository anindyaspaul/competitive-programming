#include <stdio.h>
#include <math.h>

int main()
{
    int T, i;
    double ab, ac, bc, rat;

    scanf("%d", &T);
    for ( i=1; i<=T; i++ )
    {
        scanf("%lf %lf %lf %lf", &ab, &ac, &bc, &rat);
        printf("Case %d: %lf\n", i, ab*sqrt( rat/(rat+1) ));
    }

    return 0;
}
