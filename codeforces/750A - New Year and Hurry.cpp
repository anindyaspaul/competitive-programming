#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int main()
{
    int n, k;
    cin >> n >> k;
    k = 240-k;

    int cur = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(cur + 5*i <= k) {
            cur += 5*i;
            ans++;
        }
        else break;
    }

    cout << ans << endl;

    return 0;
}
