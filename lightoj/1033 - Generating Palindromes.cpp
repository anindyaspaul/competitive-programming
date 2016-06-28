#include <bits/stdc++.h>

using namespace std;

#define MX 110

int dp[MX][MX];
char str[MX], rts[MX];

int lcs(int i, int j)
{
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ret;
    if(str[i] == rts[j]) ret = lcs(i-1, j-1) + 1;
    else ret = max(lcs(i-1, j), lcs(i, j-1));

    return dp[i][j] = ret;
}

int main()
{
    int t, cs = 1;
    scanf("%d", &t);

    while(t--) {
        scanf("%s", str);
        int len = strlen(str);
        for(int i = 0, j = len-1; i < len; i++, j--) {
            rts[i] = str[j];
        }
        rts[len] = 0;

        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", cs++, len - lcs(len-1, len-1));
    }

    return 0;
}
