#include <bits/stdc++.h>

using namespace std;

#define mx 100010

int ara[mx];

int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        bool res = false;
        for(int i = 0; i < n; i++) {
            scanf("%d", &ara[i]);
            if(i >= 2) {
                if(ara[i] == ara[i-1] && ara[i-1] == ara[i-2])
                    res = true;
            }
        }

        if(res) puts("Yes");
        else puts("No");
    }

    return 0;
}
