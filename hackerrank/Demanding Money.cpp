#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define MX 40

int money[MX];
vector <int> graph[MX];
vector <int> comp[MX];
int par[MX];
int col[MX];
bool vis[MX];
bool chk[MX][2];
pair <int, LL> dp[MX][2];

pair <int, LL> calc(int u, int g)
{
	if(chk[u][g])
		return dp[u][g];

//    cout << u << ' ' << g << endl;

    bool vua = false;
    col[u] = g;
    vis[u] = true;
	pair <int, LL> p(0, 1);
	for(int i = 0; i < graph[u].size(); i++) {
		int v = graph[u][i];
		if(!vis[v] && v != par[u]) {
			par[v] = u;
			if(g == 0) {
				pair <int, LL> ret = calc(v, 1);
				p.first += ret.first;
				p.second *= ret.second;
			}
			else {
				pair <int, LL> ret = calc(v, 0);
                p.first += ret.first;
                p.second *= ret.second;
			}
		}
		else if(col[v] == col[u]) {
            vua = true;
		}
	}

	if(vua) {
        chk[u][g] = true;
        return dp[u][g] = make_pair(0, (LL) 1);
	}

	if(g == 1) p.first += money[u];

//	cout << " " << ' ' << p.first << ' ' << p.second << endl;

	chk[u][g] = true;
	return dp[u][g] = p;
}

void dfs(int u, int cmp)
{
    vis[u] = true;
    comp[cmp].push_back(u);
    for(int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if(!vis[v]) {
            dfs(v, cmp);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> money[i+1];
    }

    while(m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cmpcnt = 0;
    memset(vis, 0, sizeof(0));
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i, cmpcnt);
            cmpcnt++;
        }
    }

    pair <int, LL> ans(0, 1);
    for(int i = 0; i < cmpcnt; i++) {
        pair <int, LL> tmpo(0, 1);
        for(int j = 0; j < comp[i].size(); j++) {
            int u = comp[i][j];

            memset(vis, 0, sizeof(0));
            memset(col, -1, sizeof(col));
            pair <int, LL> ret1 = calc(u, 0);
            memset(vis, 0, sizeof(0));
            memset(col, -1, sizeof(col));
            pair <int, LL> ret2 = calc(u, 1);

            pair <int, LL> tmp(0, 1);
            if(ret1.first > ret2.first) tmp = ret1;
            else if(ret1.first < ret2.first) tmp = ret2;
            else {
                tmp.first = ret1.first;
                tmp.second = (ret1.second + ret2.second);
            }
            if(tmp.first > tmpo.first) tmpo = tmp;
        }
        ans.first += tmpo.first;
        ans.second *= tmpo.second;
    }

    cout << ans.first << ' ' << ans.second << endl;

    return 0;
}
