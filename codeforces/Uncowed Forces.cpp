#include <bits/stdc++.h>

using namespace std;

#define mx 5

int m[mx];
int w[mx];
int x[] = {500, 1000, 1500, 2000, 2500};

int main()
{
	for(int i = 0; i < mx; i++) {
		cin >> m[i];
	}

	for(int i = 0; i < mx; i++) {
		cin >> w[i];
	}

	int hs, hu;
	cin >> hs >> hu;

	int ans = 0;
	for(int i = 0; i < mx; i++) {
		ans += max(3*x[i]/10, (250*x[i]-m[i]*x[i])/250 - 50*w[i]);
	}
	ans += hs*100;
	ans -= hu*50;

	cout << ans << endl;

    return 0;
}
