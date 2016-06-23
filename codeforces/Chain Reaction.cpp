#include <bits/stdc++.h>

using namespace std;

#define mx 1000010
#define INF 100000000

int pos[mx];
int cnt[mx];
int dp[mx];

//int calc(int take, int i)
//{
//	cout << take << ' ' << i << endl;
//	if(i == 0) return 0;
//	if(pos[i] == 0) return calc(take, i-1);
//
//	if(dp[take][i] != -1) return dp[take][i];
//
//	int ret = 0;
//	if(take) {
//		ret = calc(1, i-pos[i]-1) + cnt[i]-cnt[i-pos[i]-1];
//	}
//	else {
//		ret = min(calc(0, i-1)+1, calc(1, i-1));
//	}
//
//	return dp[take][i] = ret;
//}

int main()
{
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pos[a+1] = b;
	}

	cnt[0] = 0;
	for(int i = 1; i < mx; i++) {
		cnt[i] = cnt[i-1];
		if(pos[i] > 0) {
			cnt[i]++;

			int rev = i-pos[i]-1;
			if(rev < 0) rev = 0;
			dp[i] = dp[rev] + cnt[i-1]-cnt[rev];
		}
		else dp[i] = dp[i-1];

//		if(i < 12) cout << i-1 << ' ' << dp[i] << endl;
	}

	int ans = INF;
	int tmp = 0;
	for(int i = mx-1; i > 0; i--) {
		ans = min(ans, dp[i] + tmp);
		if(pos[i] > 0) tmp++;
	}

	cout << ans << endl;

//	memset(dp, -1, sizeof(dp));
//	cout << min(dp[0][mx-1], dp[1][mx-1]) << endl;

    return 0;
}
