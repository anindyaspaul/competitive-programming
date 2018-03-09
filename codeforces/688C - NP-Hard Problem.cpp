#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define mx 100010

int col[mx];
bool vis[mx];
bool f;

vector <int> graph[mx];
vector <int> out[2];

void dfs(int u, int c)
{
    vis[u] = true;
    col[u] = c;

    for(int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if(!vis[v]) {
            dfs(v, 1-c);
        }
        else if(col[u] == col[v]) {
            f = true;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    memset(col, -1, sizeof(col));

    while(m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 0; i < n; i++) {
        if(graph[i].size() > 0 && !vis[i]) {
            dfs(i, 0);
        }
    }

    if(f) cout << "-1" << endl;
    else {
        for(int i = 0; i < n; i++) {
            if(col[i] != -1) {
                out[col[i]].push_back(i);
            }
        }

        for(int j = 0; j < 2; j++) {
            cout << out[j].size() << endl;
            for(int i = 0; i < out[j].size(); i++) {
                if(i) cout << " ";
                cout << out[j][i]+1;
            }
            cout << endl;
        }
    }

    return 0;
}
