#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define MOD 1000000007
#define MX 10000000

LL v[MX];
LL vc[MX];
LL cum[MX];
LL cumu[MX];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t, cs = 1;
    cin >> t;

    while(t--) {
        int n, q;
        cin >> n >> q;

        cum[0] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
            cum[i] = cum[i-1] + v[i];
        }

        int k = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                vc[k] = cum[j] - cum[i-1];
                k++;
            }
        }

        sort(vc+1, vc+k);

        cumu[0] = 0;
        for(int i = 1; i < k; i++) {
            cumu[i] = cumu[i-1] + vc[i];
        }

        cout << "Case #" << cs++ << ":" << endl;

        while(q--) {
            int l, r;
            cin >> l >> r;
            cout << cumu[r] - cumu[l-1] << endl;
        }
    }

    return 0;
}
