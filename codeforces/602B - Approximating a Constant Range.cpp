#include <bits/stdc++.h>

using namespace std;

#define mx 100010
#define INF 100000000

int ara[mx];

int main()
{
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> ara[i];
	}

	int s = 0, e = 0, m = INF, M = 0, mi = 0, Mi = 0, ans = 0;
	while(e < n) {
		M = max(M, ara[e]);
		m = min(m, ara[e]);
		if(M == ara[e]) Mi = e;
		if(m == ara[e]) mi = e;
		if(M-m > 1) {
			if(M == ara[e]) {
				m = M-1;
				s = mi+1;
				for(int i = e; i >= s; i--) {
					if(ara[i] == m) {
						mi = i;
						break;
					}
				}
			}
			else {
				M = m+1;
				s = Mi+1;
				for(int i = e-1; i >= s; i--) {
					if(ara[i] == M) {
						Mi = i;
						break;
					}
				}
			}
			ans = max(ans, e-s+1);
		}
		else {
			ans = max(ans, e-s+1);
		}
		e++;
//		cout << M << ' ' << m << endl;
//		cout << "-----" << s << ' ' << e-1 << endl;
	}

	cout << ans << endl;

    return 0;
}
