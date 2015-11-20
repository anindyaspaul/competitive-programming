// Algorithm: DP, Bit-mask
// Verdict  : AC

#include <bits/stdc++.h>

using namespace std;

bool checkBit(int mask, int pos)
{
    return mask & ((int)1<<pos);
}

int setBit(int mask, int pos)
{
    return mask | ((int)1<<pos);
}

#define INF 100000000

int n;
int cost[20][20];
int dp[16390];

int calc(int mask)
{
    if(dp[mask] != -1) return dp[mask];

    int ret = INF;
    for(int i = 0; i < n; i++) {
        if(!checkBit(mask, i)) {
            int tmp = cost[i][i];
            for(int j = 0; j < n; j++) {
                if(j == i) continue;
                if(checkBit(mask, j)) tmp += cost[i][j];
            }
            ret = min(ret, calc(setBit(mask, i)) + tmp);
        }
    }

    return dp[mask] = (ret == INF) ? 0 : ret;
}

int main()
{
//    freopen("in.txt", "r", stdin);

    int t, cs = 1;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &cost[i][j]);
            }
        }

        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", cs++, calc(0));
    }

    return 0;
}
