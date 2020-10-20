#include <bits/stdc++.h>

using namespace std;

vector<int> ct;
vector<vector<bool>> g;
vector<bool> vis;

void dfs(int pos) {
    vis[pos] = true;
    for(int i = 0; i < g[pos].size(); i++) {
        if(g[pos][i]) {
            if(vis[i]) {
                g[pos][i] = 0;
            }
            else {
                dfs(i);
            }
        }
    }
}

void test_case(int kase) {
    int n;
    scanf("%d", &n);

    ct.clear();
    g.clear();
    vis.clear();
    for(int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        ct.push_back(val);
        vector<bool> tmp;
        for(int j = 0; j < n; j++) {
            tmp.push_back(true);
        }
        g.push_back(tmp);
        vis.push_back(false);
    }

    int removed = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(ct[i] == ct[j]) {
                g[i][j] = false;
                removed++;
            }
        }
    }
    
    dfs(0);
    bool possible = true;
    for(int i = 0; i < n; i++) {
        possible = possible && vis[i];
    }
    if(possible) {
        puts("YES");
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(g[i][j]) {
                    printf("%d %d\n", i+1, j+1);
                }
            }
        }
    }
    else {
        puts("NO");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++) {
        test_case(kase);
    }
    return 0;
}
