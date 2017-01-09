#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define MX 200010

int n;
int dis[MX];
int graph[MX];

void bfs(int s)
{
    queue <int> q;
    q.push(s);
    dis[s] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        int v = graph[u];

        if(v && !dis[v]) {
            dis[v] = dis[u] + 1;
            q.push(v);
        }

        if(u > 1 && !dis[u-1]) {
            dis[u-1] = dis[u] + 1;
            q.push(u-1);
        }

        if(u < n && !dis[u+1]) {
            dis[u+1] = dis[u] + 1;
            q.push(u+1);
        }
    }
}

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> graph[i];
    }

    bfs(1);

    for(int i = 1; i <= n; i++) {
        if(i > 1) cout << " ";
        cout << dis[i]-1;
    }
    cout << endl;

    return 0;
}
