#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define MOD 1000000007
#define MX 1010

int ara[4][MX];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t, cs = 1;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < n; j++) {
                cin >> ara[i][j];
            }
        }

        map <int, LL> mp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int t1 = ara[0][i];
                int t2 = ara[1][j];
                mp[t1^t2]++;
            }
        }

        LL cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int t1 = ara[2][i];
                int t2 = ara[3][j];
                int q = t1^t2^k;

                if(mp.find(q) != mp.end()) cnt += mp[q];
            }
        }

        cout << "Case #" << cs++ << ": " << cnt << endl;
    }

    return 0;
}
