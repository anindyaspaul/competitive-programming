// Algorithm: DP, Knapsack
// Verdict  :

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

bool checkBit(LL mask, LL pos)
{
	return (mask & ((LL) 1 << pos)) == (LL) 0;
}

LL setBit(LL mask, LL pos)
{
	return mask | ((LL) 1 << pos);
}

#define INF 100000000

#define VM 32010
#define NM 70

int n;
int v[NM], c[NM], u[NM];

int calc(int i, int cap, LL mask)
{
	if(i == n) return 0;

	if(checkBit(mask, i)) return calc(i+1, cap, mask);

	int ret = calc(i+1, cap, mask);
	if(u[i] == -1) { // no dependency
		if(v[i] <= cap) {
			ret = max(ret, calc(i+1, cap-v[i], setBit(mask, i)) + v[i]*c[i]);
		}
	}
	else if(u[i] < i) {
		if(v[i] <= cap && checkBit(mask, u[i])) {
			ret = max(ret, calc(i+1, cap-v[i], setBit(mask, i)) + v[i]*c[i]);
		}
	}
	else {
		if(v[i]+v[u[i]] <= cap) {
			ret = max(ret, calc(i+1, cap-v[i]-v[u[i]], setBit(setBit(mask, u[i]), i))
				+ v[i]*c[i] + v[u[i]]*c[u[i]]);
		}
	}

	return ret;
}

int main()
{
	freopen("in.txt", "r", stdin);

	int t;
	scanf("%d", &t);

	while(t--) {
		int cap;
		scanf("%d %d", &cap, &n);

		for(int i = 0; i < n; i++) {
			scanf("%d %d %d", &v[i], &c[i], &u[i]);
			u[i]--;
		}

		printf("%d\n", calc(0, cap, 0));
	}

	return 0;
}
