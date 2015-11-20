// Algorithm: DP
// Verdict  : AC

#include <bits/stdc++.h>

using namespace std;

#define MX 1010

int n;
int dim[MX][2];
int dp[MX][MX];

int calc(int i, int prev)
{
	if(i == n) return 0;
	if(dp[i][prev] != -1) return dp[i][prev];

	int ret1 = calc(i+1, dim[i][0]) + dim[i][1] +
		max(prev, dim[i][0]) - min(prev, dim[i][0]);
	if(i == 0) ret1 -= max(prev, dim[i][0]) - min(prev, dim[i][0]);

	int ret2 = calc(i+1, dim[i][1]) + dim[i][0] +
		max(prev, dim[i][1]) - min(prev, dim[i][1]);
	if(i == 0) ret2 -= max(prev, dim[i][1]) - min(prev, dim[i][1]);

	return dp[i][prev] = max(ret1, ret2);
}

int main()
{
//	freopen("in.txt", "r", stdin);

	scanf("%d\n", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &dim[i][0], &dim[i][1]);
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", calc(0, 0));

	return 0;
}
