#include <stdio.h>

int main()
{
    int t, i, j, n, d, total;

    scanf("%d", &t);
    for (i=1, total=0; i<=t; i++, total=0) {
        scanf("%d", &n);
        for (j=1; j<=n; j++) {
            scanf("%d", &d);
            if (d<0)    continue;
            total = total+d;
        }
        printf("Case %d: %d\n", i, total);
        }

    return 0;
}
