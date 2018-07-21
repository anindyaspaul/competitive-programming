#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define MX 10010

bool vis[MX];
int a[MX], b[MX];

int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        LL sum = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", b+i);
            sum += b[i];
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", a+i);
            sum += a[i];
        }

        if(sum % n != 0) {
            puts("-1");
            continue;
        }

        bool gg = false;
        int goal = sum / n;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++) {
            if(i > 0 && !vis[i-1]) {
                a[i] += b[i-1];
            }

            int need = goal-a[i];

            if(need == b[i] && !vis[i]) {
                a[i] += need;
                vis[i] = true;
            }
            else if(i < n-1 && need == b[i]+b[i+1] && !vis[i] && !vis[i+1]) {
                a[i] += need;
                vis[i] = true;
                vis[i+1] = true;
            }
            else if(i < n-1 && need == b[i+1]  && !vis[i+1]) {
                a[i] += need;
                vis[i+1] = true;
            }

            if(a[i] != goal) gg = true;

//            cout << " " << a[i];
        }

        if(gg) puts("-1");
        else printf("%d\n", goal);

    }

    return 0;
}
