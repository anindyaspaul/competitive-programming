#include <stdio.h>

int main()
{
    int T, i, mpos, lpos, t, floor;

    scanf("%d", &T);
    for ( i=1; i<=T; i++ )
    {
        scanf("%d %d", &mpos, &lpos);
        if ( mpos>lpos )    floor = mpos-lpos;
        else                floor = lpos-mpos;
        t = floor*4 + mpos*4 + 19;
        printf("Case %d: %d\n", i, t);
    }

    return 0;
}
