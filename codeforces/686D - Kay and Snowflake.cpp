#include <bits/stdc++.h>

using namespace std;

#define mx 300010

int n, q;

int par[mx];
int cent[mx];
int tSize[mx];
int subSize[mx];

vector <int> graph[mx];

bool isCent(int c, int u)
{
    if(2*subSize[c] <= tSize[u] && 2*(tSize[u]-tSize[c]) <= tSize[u]) return true;
    return false;
}

void dfs(int u, int p)
{
    par[u] = p;
    tSize[u] = 1;
    subSize[u] = 0;
    cent[u] = u;

    int ptr = -1;
    for(int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if(v == p) continue;

        dfs(v, u);
        tSize[u] += tSize[v];
        subSize[u] = max(subSize[u], tSize[v]);
        if(subSize[u] == tSize[v])
            ptr = i;
    }

    if(ptr == -1) return;

    int c = cent[graph[u][ptr]];
    while(!isCent(c, u)) {
        c = par[c];
    }
    cent[u] = c;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    cin >> n >> q;

    for(int i = 0; i < n-1; i++) {
        int u;
        cin >> u;
        graph[u].push_back(i+2);
        graph[i+2].push_back(u);
    }

    dfs(1, 1);

    for(int i = 0; i < q; i++) {
        int u;
        cin >> u;
        cout << cent[u] << endl;
    }

    return 0;
}
