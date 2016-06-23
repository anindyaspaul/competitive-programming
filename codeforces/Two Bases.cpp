#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

int main()
{
	int n, x, m, y, b;

	cin >> n >> x;

	ULL ans1 = 0;
	for(int i = 0; i < n; i++) {
		cin >> b;
		ans1 *= x;
		ans1 += b;
	}

	cin >> m >> y;
	ULL ans2 = 0;
	for(int i = 0; i < m; i++) {
		cin >> b;
		ans2 *= y;
		ans2 += b;
	}

	if(ans1 < ans2) cout << "<" << endl;
	else if(ans1 > ans2) cout << ">" << endl;
	else cout << "=" << endl;

    return 0;
}
