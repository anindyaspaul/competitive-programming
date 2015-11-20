// Algorithm: DP, Knapsack
// Verdict  :

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

bool checkBit(LL mask, LL pos)
{
	return (mask & ((LL) 1 << pos));
}

LL setBit(LL mask, LL pos)
{
	return mask | ((LL) 1 << pos);
}

#define INF 100000000

#define VM 32010
#define NM 70

int n;
int u[NM], uc[NM];
vector <int> v[NM], vc[NM];

int CS;
int dp[NM][VM];
int chk[NM][VM];

int calc(int i, int cap)
{
	if(i == n) return 0;
	if(chk[i][cap] == CS) return dp[i][cap];

	int ret1 = calc(i+1, cap);

	int ret2 = 0;
	if(u[i] != -1 && u[i] <= cap) {
		cap -= u[i];
		ret2 = u[i]*uc[i];
		int tmp = calc(i+1, cap);
		if(v[i].size() > 0) {
			if(v[i][0] <= cap)
				tmp = max(tmp, calc(i+1, cap-v[i][0]) + v[i][0]*vc[i][0]);
		}
		if(v[i].size() > 1) {
			if(v[i][1] <= cap)
				tmp = max(tmp, calc(i+1, cap-v[i][1]) + v[i][1]*vc[i][1]);
			if(v[i][0]+v[i][1] <= cap)
				tmp = max(tmp, calc(i+1, cap-v[i][0]-v[i][1])
					+ v[i][0]*vc[i][0] + v[i][1]*vc[i][1]);
		}
		ret2 += tmp;
	}

	chk[i][cap] = CS;
	return dp[i][cap] = max(ret1, ret2);
}

int main()
{
	// freopen("in.txt", "r", stdin);

	int t;
	scanf("%d", &t);

	CS = 1;
	while(t--) {
		int cap;
		scanf("%d %d", &cap, &n);

		for(int i = 0; i < n; i++) {
			v[i].clear();
			vc[i].clear();
		}

		for(int i = 0; i < n; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			if(z == 0) {
				u[i] = x;
				uc[i] = y;
			}
			else {
				u[i] = -1;
				uc[i] = 0;
				v[z-1].push_back(x);
				vc[z-1].push_back(y);
			}
		}

		CS++;
		printf("%d\n", calc(0, cap));
	}

	return 0;
}
