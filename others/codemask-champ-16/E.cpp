#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, cs = 1;

    scanf("%d", &t);
    while(t--) {

        long long int n;
        scanf("%lld", &n);

        printf("Case %d: ", cs++);
        if((n% (long long int) 2) == (long long int) 0) printf("%lld\n", n/2);
        else printf("%lld\n", n);
    }

    return 0;
}
