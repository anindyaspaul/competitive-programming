#include <bits/stdc++.h>

using namespace std;

#define scani(x) scanf("%d", &x)
#define scans(x) scanf("%s", x)

#define MX 15
#define MXX 110

char grid[MX][MX];
bool vis[MXX][MXX][MXX];
bool finflg[MXX];
int dis[MXX][MXX][MXX];

class Node {
public:
    int ap, bp, cp;

    Node(int a, int b, int c)
    {
        ap = a;
        bp = b;
        cp = c;
    }
};

int bfs(int as, int bs, int cs, int n)
{
    queue <Node> q;
    q.push(Node(as, bs, cs));
    vis[as][bs][cs] = true;
    dis[as][bs][cs] = 0;

    while(!q.empty()) {
        Node nd = q.front();
        q.pop();

        int ap = nd.ap;
        int bp = nd.bp;
        int cp = nd.cp;

        if(finflg[ap][bp][cp]) return dis[as][bs][cs];

        int an, bn, cn;
        // move north
        if(ap >= n && grid[][] != '#')
    }

    return -1;
}

int main()
{
    int t, CS = 1;
    scani(t);

    while(t--) {

        int n;
        scani(n);

        int as, bs, cs;
        for(int i = 0; i < n; i++) {
            scans(grid[i]);
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 'A') as = i*n + j;
                else if(grid[i][j] == 'B') bs = i*n + j;
                else if(grid[i][j] == 'C') cs = i*n + j;
                else if(grid[i][j] == 'X') finflg[i*n + j] = true;
            }
        }

        int ans = bfs(as, bs, cs, n);

        printf("Case %d: ", CS++);
        if(ans == -1) puts("trapped");
        else printi(ans);
    }

    return 0;
}
