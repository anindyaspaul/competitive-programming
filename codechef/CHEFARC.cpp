#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define MX 110
#define INF 1000000010

int n, m, k[2];
int grid[MX][MX];
int dis[2][MX][MX];

class Node {
public:
    int r, c, stp, kk;
    Node(int e, int f, int g)
    {
        r = e;
        c = f;
        stp = g;
    }
};

int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1};

/**
      0,2   1,2    2,2
      0,1   1,1    2,1
      0,0   1,0   2,0

*/

bool isok(int r, int c)
{
    if(r < 0 || c < 0 || r >= n || c >= m) return false;
    return true;
}

void bfs(int r, int c, int id)
{
    queue <Node> q;
    q.push(Node(r, c, 0));
    dis[id][r][c] = 0;

    int cnt = 0;
    while(!q.empty()) {
        cnt++;
        Node nd = q.front();
        q.pop();

        r = nd.r;
        c = nd.c;
        int stp = nd.stp;

        if(k[id] == 0) continue;
        for(int i = 0; i <= k[id]; i++) {
            for(int j = 0; i+j <= k[id]; j++) {
                for(int d = 0; d < 4; d++) {
                    int nr = r+i*dx[d];
                    int nc = c+j*dy[d];

                    if(isok(nr, nc)) {
                        if(!grid[nr][nc] && dis[id][nr][nc] > stp+1) {
                            dis[id][nr][nc] = stp+1;
                            q.push(Node(nr, nc, stp+1));
                        }
                    }
                }
            }
        }
    }
//    cout << "cnt " << cnt << endl;
}

int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d %d %d %d", &n, &m, &k[0], &k[1]);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                scanf("%d", &grid[i][j]);
                dis[0][i][j] = INF;
                dis[1][i][j] = INF;
            }
        }

        bfs(0, 0, 0);   // robot0
        bfs(0, m-1, 1); // robot1

        int res = INF;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res = min(res, max(dis[0][i][j], dis[1][i][j]));
            }
        }
/*
        cout << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << " " << dis[0][i][j];
            }
            cout << endl;
        }
        cout << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << " " << dis[1][i][j];
            }
            cout << endl;
        }
*/
        if(res == INF) puts("-1");
        else printf("%d\n", res);
    }

    return 0;
}
