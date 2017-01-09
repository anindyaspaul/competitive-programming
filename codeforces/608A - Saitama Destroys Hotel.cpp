#include <bits/stdc++.h>

using namespace std;

#define mx 1010

int fl[mx];

int main()
{
	int n, s;
	cin >> n >> s;

	for(int i = 0; i < n; i++) {
		int f, t;
		cin >> f >> t;
		fl[f] = max(fl[f], t);
	}

	int ans = 0;
	int cur = 0;
	for(int i = s; i >= 0; i--) {
		if(cur < fl[i]) {
			cur = fl[i];
		}
		if(i) cur++;
	}

	cout << cur << endl;

    return 0;
}
