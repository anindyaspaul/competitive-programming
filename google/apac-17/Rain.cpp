#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define INF 1000000010
#define MAX 60

int r, c;
int grid[MAX][MAX];
int bak[MAX][MAX];
bool vis[MAX][MAX];
set <int> st;

int dfs(int i, int j)
{
    vis[i][j] = true;
    int ret = INF;
    if(i < r-1) {
        if(grid[i+1][j] > grid[i][j]) ret = min(ret, grid[i+1][j]);
        else if(i+1 == r-1) ret = min(ret, grid[i][j]);
        else if(!vis[i+1][j]) ret = min(ret, dfs(i+1, j));
    }
    if(i > 0) {
        if(grid[i-1][j] > grid[i][j]) ret = min(ret, grid[i-1][j]);
        else if(i-1 == 0) ret = min(ret, grid[i][j]);
        else if(!vis[i-1][j]) ret = min(ret, dfs(i-1, j));
    }
    if(j < c-1) {
        if(grid[i][j+1] > grid[i][j]) ret = min(ret, grid[i][j+1]);
        else if(j+1 == c-1) ret = min(ret, grid[i][j]);
        else if(!vis[i][j+1]) ret = min(ret, dfs(i, j+1));
    }
    if(j > 0) {
        if(grid[i][j-1] > grid[i][j]) ret = min(ret, grid[i][j-1]);
        else if(j-1 == 0) ret = min(ret, grid[i][j]);
        else if(!vis[i][j-1]) ret = min(ret, dfs(i, j-1));
    }
//    cout << i << " " << j << " " << ret << endl;
    return ret;
}

void fill(int i, int j, int w)
{
    grid[i][j] = w;
    if(i < r-1) {
        if(grid[i+1][j] < w) fill(i+1, j, w);
    }
    if(i > 0) {
        if(grid[i-1][j] < w) fill(i-1, j, w);
    }
    if(j < c-1) {
        if(grid[i][j+1] < w) fill(i, j+1, w);
    }
    if(j > 0) {
        if(grid[i][j-1] < w) fill(i, j-1, w);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t, cs = 1;
    cin >> t;

    while(t--) {
        cin >> r >> c;

        st.clear();
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cin >> grid[i][j];
                bak[i][j] = grid[i][j];
                st.insert(grid[i][j]);
            }
        }

        for(auto h: st) {
//            cout << h << endl;
            memset(vis, 0, sizeof(vis));
            for(int i = 1; i < r-1; i++) {
                for(int j = 1; j < c-1; j++) {
                    if(grid[i][j] == h && !vis[i][j]) {
                        int w = dfs(i, j);
                        if(w > h) fill(i, j, w);
                    }
                }
            }
        }

        int sum = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
//                cout << grid[i][j] << " ";
                sum += grid[i][j] - bak[i][j];
            }
//            cout << endl;
        }

        cout << "Case #" << cs++ << ": "<< sum << endl;
    }

    return 0;
}
