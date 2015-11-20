// Algorithm: DP
// Verdict  : AC

#include <bits/stdc++.h>

using namespace std;

#define INF 100000000

#define MX 2010

int K, la, lb;
char A[MX], B[MX];
int dp[MX][MX];

int calc(int i, int j)
{
	if(i >= la && j >= lb) return 0;

	if(i >= la) return K*(lb-j);
	if(j >= lb) return K*(la-i);

	if(dp[i][j] != -1) return dp[i][j];

	int ret = INF;
	ret = min(ret, calc(i+1, j+1) + abs(A[i]-B[j]));
	ret = min(ret, calc(i, j+1) + K);
	ret = min(ret, calc(i+1, j) + K);

	return dp[i][j] = ret;
}

int main()
{
	scanf("%s", A);
	scanf("%s", B);
	scanf("%d", &K);

	la = strlen(A);
	lb = strlen(B);

	memset(dp, -1, sizeof(dp));
	printf("%d\n", calc(0, 0));

	return 0;
}
