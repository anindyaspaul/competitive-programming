#include <bits/stdc++.h>

using namespace std;

#define mx 100010

char str[mx];
int dp[mx];

int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", str);

	dp[0] = 1;
	for(int i = 1; i < n; i++) {
		if(str[i] == str[i-1]) dp[i] = dp[i-1];
		else dp[i] = dp[i-1] + 1;
	}

	int ans = 1;
	int l = 0, r = 0;
	while(l < n) {
		if(r == l) r++;
		else if(r == n) {
			int mxi = r-l;
			bool flg = false;
			int prev = l;
			for(int i = l-1; i >= 0; i--) {
				if(!flg) {
					if(str[i] == str[prev]) {
						mxi += dp[i];
						break;
					}
				}
				else {
					if(str[i] != str[prev]) {
						mxi += dp[i];
						break;
					}
				}
			}
			ans = max(ans, mxi);
			l = r;
		}
		else if(str[r] != str[r-1]) r++;
		else {
			int mxi = r-l;
			bool flg = false;
			int prev = l;
			for(int i = l-1; i >= 0; i--) {
				if(!flg) {
					if(str[i] == str[prev]) {
						mxi += dp[i];
						break;
					}
				}
				else {
					if(str[i] != str[prev]) {
						mxi += dp[i];
					}
				}
			}
			mxi += dp[n-1] - dp[r-1] + 1;
			ans = max(ans, mxi);
			l = r;
		}
	}

	printf("%d\n", ans);

    return 0;
}
