#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int main()
{
    LL t, k, n, cs = 1;

    scanf("%lld", &t);
    while(t--) {

        scanf("%lld %lld", &k, &n);
        printf("Case %lld:\n", cs++);

        if(k == 0) {
            printf("%lld\n", n/3);
            printf("%lld\n", ((2*n/3)/3)*2);
            printf("%lld\n", (2*n/3)/3);
        }
        else {
            printf("%lld\n", ((3*n)/2));
            printf("%lld\n", 2*n);
            printf("%lld\n", 3*((3*n)/2));
        }
    }

    return 0;
}
