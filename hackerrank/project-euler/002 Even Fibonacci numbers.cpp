#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define MX 82

LL fib[MX];

int main()
{
    fib[1] = 1;
    fib[2] = 2;
    for(int i = 3; i < MX; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    LL t;
    scanf("%lld", &t);

    while(t--) {
        LL n;
        scanf("%lld", &n);

        LL sum = 0;
        for(int i = 1; fib[i] <= n; i++) {
            if(fib[i]%2 == 0) {
                sum += fib[i];
            }
        }

        printf("%lld\n", sum);
    }

    return 0;
}
