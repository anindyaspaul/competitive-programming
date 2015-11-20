// Algorithm: DP, Knapsack
// Verdict  : AC

#include <bits/stdc++.h>

using namespace std;

#define MX 1010
#define INF 100000000

int CS;
int o, n, c;
int oa[MX], na[MX], wa[MX];
int dp[MX][30][100];
int chk[MX][30][100];

int calc(int i, int co, int cn)
{
	if(co >= o && cn >= n) return 0;
	if(i >= c) return INF;

	if(chk[i][co][cn] == CS) return dp[i][co][cn];

	int ret1 = calc(i+1, min(co+oa[i], o), min(cn+na[i], n)) + wa[i];
	int ret2 = calc(i+1, co, cn);

	chk[i][co][cn] = CS;
	return dp[i][co][cn] = min(ret1, ret2);
}

int main()
{
//	freopen("in.txt", "r", stdin);

	int t;
	scanf("%d", &t);

	CS = 0;
	while(t--) {
                scanf("%d %d", &o, &n);
		scanf("%d", &c);
		for(int i = 0; i < c; i++) {
			scanf("%d %d %d", &oa[i], &na[i], &wa[i]);
		}

		CS++;
		printf("%d\n", calc(0, 0, 0));
	}

	return 0;
}
