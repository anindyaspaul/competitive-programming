#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define mx 1010

int n;
bool chk[mx];
LL dp[mx][mx];
bool vis[mx][mx];
bool graph[mx][mx];
LL w[mx];
LL b[mx];
LL bg[mx];
LL wg[mx];
LL bsum;
LL wsum;
LL len;

vector <LL> vcw, vcb, vcbg, vcwg, idx;

LL calc(int i, int cap)
{
    if(i >= n) return 0;
    if(cap <= 0) return 0;

    if(vis[i][cap]) return dp[i][cap];

    LL ret = 0;
    if(vcw[i] <= cap) ret = max(ret, calc(idx[i], cap-vcw[i]) + vcb[i]);
    if(vcwg[i] <= cap) ret = max(ret, calc(idx[i], cap-vcwg[i]) + vcbg[i]);
    ret = max(ret, calc(i+1, cap));

    vis[i][cap] = true;
    return dp[i][cap] = ret;
}

void dfs(int i)
{
    chk[i] = true;
    len++;
    bsum += b[i];
    wsum += w[i];
    for(int j = 0; j < n; j++) {
        if(i != j && graph[i][j] && !chk[j]) {
            dfs(j);
        }
    }
    bg[i] = bsum;
    wg[i] = wsum;
    vcw.push_back(w[i]);
    vcb.push_back(b[i]);
    vcwg.push_back(wg[i]);
    vcbg.push_back(bg[i]);
}

int main()
{
    int m, cap;
    scanf("%d %d %d", &n, &m, &cap);

    for(int i = 0; i < n; i++) {
        scanf("%I64d", &w[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%I64d", &b[i]);
    }
    while(m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        graph[u][v] = true;
        graph[v][u] = true;
    }

    for(int i = 0; i < n; i++) {
        if(!chk[i]) {
            bsum = 0;
            wsum = 0;
            len = 0;
            dfs(i);

            LL init = idx.size()+len;
            while(len--) idx.push_back(init);
        }
    }

    printf("%I64d\n", calc(0, cap));

    return 0;
}
