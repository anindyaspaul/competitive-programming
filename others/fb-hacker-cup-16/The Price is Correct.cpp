#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define mx 100010

LL ara[mx];

int main()
{
	freopen("the_price_is_correct.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t, cs = 1;
	scanf("%d", &t);

	while(t--) {
		LL p, n;
		scanf("%lld %lld", &n, &p);

		for(LL i = 0; i < n; i++) {
			scanf("%lld", &ara[i]);
		}

		LL l = 0, r = 0, sum = 0, ans = 0;
		while(r < n) {
			if(sum + ara[r] <= p) {
				sum += ara[r];
				ans += (r-l+1);
				r++;
			}
			else {
				if(r == l) {
					sum = 0;
					r++;
					l++;
				}
				else {
					sum -= ara[l];
					l++;
				}
			}
		}

		printf("Case #%d: %lld\n", cs++, ans);
	}

	return 0;
}
