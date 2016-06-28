#include <stdio.h>

int main()
{
    int n, T, a, b, i;
    scanf("%d", &T);
    for(i=1; i<=T; i++) {
        scanf("%d", &n);
        if(n>=2) {
            a = n-2;
            if(a>10) {
                a = n-10;
                printf("%d %d\n", a, 10);
            }
            else {
                printf("%d %d\n", a, 2);
            }
        }
        else {
            printf("%d %d\n", n-0, 0);
        }
    }
    return 0;
}
