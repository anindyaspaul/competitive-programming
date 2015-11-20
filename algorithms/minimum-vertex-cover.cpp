#include <bits/stdc++.h>

using namespace std;

#define MX 100020
#define MOD 10007

int par[MX];
vector <int> graph[MX];

int CS;
int chk[MX][2];
pair <int, int> dp[MX][2];

/* pair.first	- minimum cover
 * pair.second	- total ways to do the cover
 */
pair <int, int> calc(int u, int g)
{
	if(chk[u][g] == CS)
		return dp[u][g];

	pair <int, int> p(0, 1);
	for(int i = 0; i < graph[u].size(); i++) {
		int v = graph[u][i];
		if(v != par[u]) {
			par[v] = u;
			if(g == 0) {
				pair <int, int> ret = calc(v, 1);
				p.first += ret.first;
				p.second *= ret.second;
			}
			else {
				pair <int, int> ret1 = calc(v, 0);
				pair <int, int> ret2 = calc(v, 1);
				if(ret1.first < ret2.first) {
					p.first += ret1.first;
					p.second *= ret1.second;
				}
				else if(ret1.first > ret2.first) {
					p.first += ret2.first;
					p.second *= ret2.second;
				}
				else {
					p.first += ret1.first;
					p.second *= (ret1.second + ret2.second);
				}
			}
			p.second %= MOD;
		}
	}

	p.first += g;

	chk[u][g] = CS;
	return dp[u][g] = p;
}

int main()
{
	// freopen("in.txt", "r", stdin);

	int t;
	scanf("%d", &t);

	CS = 1;
	while(t--) {
		int n;
		scanf("%d", &n);

		for(int i = 0; i < n; i++) {
			graph[i].clear();
			par[i] = i;
		}

		int u, v;
		for(int i = 0; i < n-1; i++) {
			scanf("%d %d", &u, &v);
			u--;
			v--;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		CS++;
		pair <int, int> ret1 = calc(0, 0);
		pair <int, int> ret2 = calc(0, 1);

		pair <int, int> ans;
		if(ret1.first < ret2.first) ans = ret1;
		else if(ret1.first > ret2.first) ans = ret2;
		else {
			ans.first = ret1.first;
			ans.second = (ret1.second + ret2.second) % MOD;
		}

		printf("%d %d\n", ans.first, ans.second);
	}

	return 0;
}
