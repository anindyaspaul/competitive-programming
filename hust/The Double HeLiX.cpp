// Algorithm: DP
// Verdict  : AC

#include <bits/stdc++.h>

using namespace std;

#define MX 10010

int cnt;
int n, m, CS;
int A[2][MX];
int mt[2][MX];
int dp[2][MX];
int chk[2][MX];

int calc(int ptr, int i)
{
//	cnt++;
//	cout << ptr << ' ' << i << endl;
//	if(cnt == 20) exit(0);
	if(ptr == 0 && i == n) return 0;
	if(ptr == 1 && i == m) return 0;

	if(chk[ptr][i] == CS) return dp[ptr][i];

	int ret = calc(ptr, i+1);
	if(mt[ptr][i] != -1) ret = max(ret, calc(1-ptr, mt[ptr][i]+1));

	chk[ptr][i] = CS;
	return dp[ptr][i] = ret + A[ptr][i];
}#include <bits/stdc++.h>

using namespace std;

#define MX 10010

int cnt;
int n, m, CS;
int A[2][MX];
int mt[2][MX];
int dp[2][MX];
int chk[2][MX];

int calc(int ptr, int i)
{
//	cnt++;
//	cout << ptr << ' ' << i << endl;
//	if(cnt == 20) exit(0);
	if(ptr == 0 && i == n) return 0;
	if(ptr == 1 && i == m) return 0;

	if(chk[ptr][i] == CS) return dp[ptr][i];

	int ret = calc(ptr, i+1);
	if(mt[ptr][i] != -1) ret = max(ret, calc(1-ptr, mt[ptr][i]+1));

	chk[ptr][i] = CS;
	return dp[ptr][i] = ret + A[ptr][i];
}

int main()
{
//	freopen("in.txt", "r", stdin);

	CS = 1;
	cnt = 0;
	while(scanf("%d", &n) && n != 0) {

		for(int i = 0; i < n; i++) {
			scanf("%d", &A[0][i]);
		}
		scanf("%d", &m);
		for(int i = 0; i < m; i++) {
			scanf("%d", &A[1][i]);
		}

		memset(mt, -1, sizeof(mt));
		for(int i = 0, j = 0; i < n && j < m; ) {
			if(A[0][i] < A[1][j]) {
				i++;
			}
			else if(A[0][i] > A[1][j]) {
				j++;
			}
			else {
				mt[0][i] = j;
				mt[1][j] = i;
				i++;
				j++;
			}
		}

//		for(int i = 0; i < n; i++) {
//			cout << i << ' ' << mt[0][i] << ' ' << mt[1][i] << endl;
//		}

		CS++;
//		calc(0, 0);
		printf("%d\n", max(calc(0, 0), calc(1, 0)));
	}

	return 0;
}


int main()
{
//	freopen("in.txt", "r", stdin);

	CS = 1;
	cnt = 0;
	while(scanf("%d", &n) && n != 0) {

		for(int i = 0; i < n; i++) {
			scanf("%d", &A[0][i]);
		}
		scanf("%d", &m);
		for(int i = 0; i < m; i++) {
			scanf("%d", &A[1][i]);
		}

		memset(mt, -1, sizeof(mt));
		for(int i = 0, j = 0; i < n && j < m; ) {
			if(A[0][i] < A[1][j]) {
				i++;
			}
			else if(A[0][i] > A[1][j]) {
				j++;
			}
			else {
				mt[0][i] = j;
				mt[1][j] = i;
				i++;
				j++;
			}
		}

//		for(int i = 0; i < n; i++) {
//			cout << i << ' ' << mt[0][i] << ' ' << mt[1][i] << endl;
//		}

		CS++;
//		calc(0, 0);
		printf("%d\n", max(calc(0, 0), calc(1, 0)));
	}

	return 0;
}
