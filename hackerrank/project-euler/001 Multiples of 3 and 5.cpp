#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int main()
{
    LL t;
    scanf("%lld", &t);

    while(t--) {
        LL n;
        scanf("%lld", &n);

        n--;
        LL n3 = n/3;
        LL n5 = n/5;
        LL n15 = n/15;
        printf("%lld\n", 3*n3*(n3+1)/2 + 5*n5*(n5+1)/2 - 15*n15*(n15+1)/2);
    }

    return 0;
}
