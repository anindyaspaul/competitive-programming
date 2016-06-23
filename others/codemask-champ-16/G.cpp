#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, cs = 1;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            ans = max(ans, abs(x));
        }

        printf("Case %d: %d\n", cs++, ans);
    }

    return 0;
}
