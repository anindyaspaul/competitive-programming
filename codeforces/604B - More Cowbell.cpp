#include <bits/stdc++.h>

using namespace std;

#define mx 100010

int s[mx];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}

	int ans = 0, i = n-1;
	for( ; i >= 0; i--) {
		if(i <= 2*(k-1)) {
			ans = max(ans, s[i]);
			k--;
		}
		else break;
	}

	for(int j = 0; j < i; j++, i--) {
		ans = max(ans, s[i]+s[j]);
	}

	printf("%d\n", ans);

    return 0;
}
