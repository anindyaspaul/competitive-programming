#include <bits/stdc++.h>

using namespace std;

#define mx 2010

typedef long long LL;

int x[mx], y[mx];

class Line {
public:
	LL len;
	pair <int, int> p1, p2;

	bool operator<(const Line &l) const
	{
		if(len != l.len) return len < l.len;
		if(p1 != l.p1) return p1 < l.p1;
		if(p2 != l.p2) return p2 < l.p2;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {

		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &x[i], &y[i]);
		}

		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				for(int k = j+1; k < n; k++) {

				}
			}
		}
	}

	return 0;
}
