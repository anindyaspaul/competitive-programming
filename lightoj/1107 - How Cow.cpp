#include <stdio.h>

int main()
{
    int T, i, x1, y1, x2, y2, M, x, y;
    scanf("%d", &T);
    for(i=1; i<=T; i++)
    {
        printf("Case %d:\n", i);
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &M);
        while(M--)
        {
            scanf("%d %d", &x, &y);
            if(x>x1 && y>y1)
            {
                if(x<x2 && y<y2)
                {
                    printf("Yes\n");
                }
                else
                {
                    printf("No\n");
                }
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}
