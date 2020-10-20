// Explanation: https://codeforces.com/blog/entry/79974

#include <bits/stdc++.h>

using namespace std;

void test_case(int kase) {
    int n;
    scanf("%d", &n);

	int res = 1;
	for(int i = 2; i*i <= n; i++) {
		if(n%i == 0) {
			res = n/i;
			break;
		}
	}
	printf("%d %d\n", res, n-res);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++) {
        test_case(kase);
    }
    return 0;
}
