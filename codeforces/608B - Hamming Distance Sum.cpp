#include <bits/stdc++.h>

using namespace std;

#define mx 200010

char a[mx];
char b[mx];
long long dp[2][mx];

int main()
{
	scanf("%s", a);
	scanf("%s", b);

	int la = strlen(a);
	int lb = strlen(b);

	dp[0][0] = dp[1][0] = 0;
	for(int i = 1; i <= lb; i++) {
		dp[0][i] = dp[0][i-1] + abs(b[i-1]-'0');
		dp[1][i] = dp[1][i-1] + abs(b[i-1]-'1');
	}

	long long sum = 0;
	for(int i = 0; i < la; i++) {
		if(a[i] == '0') {
			sum += (dp[0][lb-la+i+1] - dp[0][i]);
		}
		else {
			sum += (dp[1][lb-la+i+1] - dp[1][i]);
		}
	}

	cout << sum << endl;

    return 0;
}
