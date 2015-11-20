// Algorithm: DP
// Verdict  : AC

#include <bits/stdc++.h>

using namespace std;

#define INF 100000000

#define MX 30

int n, hire, sal, term;
int req[MX];

map <pair<int, int>, int> dp;

int calc(int i, int cur)
{
//	if(i == n-1) {
//		if(cur < req[i]) return (req[i]-cur)*hire + req[i]*sal;
//		else return cur*sal;
//	}
	if(i == n) return 0;
	if(dp.find(make_pair(i, cur)) != dp.end())
		return dp[make_pair(i, cur)];

	int ret = INF;

	if(cur < req[i]) {
		ret = calc(i+1, req[i]) + (req[i]-cur)*hire + req[i]*sal;
	}
	else {
		for(int j = cur; j >= req[i]; j--) {
			ret = min(ret, calc(i+1, j) + (cur-j)*term + j*sal);
		}
	}

	return dp[make_pair(i, cur)] = ret;
}

int main()
{
//	freopen("in.txt", "r", stdin);

	int cs = 1;

	while(scanf("%d", &n) && n != 0) {

		scanf("%d %d %d", &hire, &sal, &term);

		for(int i = 0; i < n; i++) {
			scanf("%d", &req[i]);
		}

		dp.clear();
		printf("Case %d, cost = $%d\n", cs++, calc(0, 0));
	}

	return 0;
}
