#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int sum = 0;
        bool fail = false;
        bool five = false;
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if(x == 2) fail = true;
            if(x == 5) five = true;
            sum += x;
        }

        if(fail || !five || sum < 4*n) puts("No");
        else puts("Yes");

    }

    return 0;
}
