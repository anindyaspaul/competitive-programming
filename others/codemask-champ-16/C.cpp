#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, cs = 1;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        printf("Case %d: %d\n", cs++, 2*(n-1));
    }

    return 0;
}
