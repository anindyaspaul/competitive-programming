#include <bits/stdc++.h>

using namespace std;

bool vis[10];

bool done()
{
	for(int i = 0; i < 10; i++) {
		if(!vis[i]) return false;
	}
	return true;
}

void check(long long x)
{
	while(x > 0) {
		vis[x%10] = true;
		x /= 10;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t, cs = 1;

	scanf("%d", &t);

	while(t--) {
		long long n;
		scanf("%lld", &n);

		printf("Case #%d: ", cs++);

		if(n == 0) {
			printf("INSOMNIA\n");
			continue;
		}

		memset(vis, 0, sizeof(vis));

		long long i = 0;
		while(!done()) {
			i++;
			check(n*i);
		}

		printf("%lld\n", n*i);
	}

	return 0;
}
