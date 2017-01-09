#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define MX 101

LL cnt[MX];

LL cube(LL x)
{
    return x*x*x;
}

LL calc(LL n)
{
    LL cnt = 0;
    for(LL k = 2; cube(k) <= n; k++) {
        cnt += n/cube(k);
    }
    return cnt;
}

int main()
{
    LL m;
    cin >> m;

    LL low = 0;
    LL high = (LL) 1 << 62;
    while(low < high) {
        LL mid = (low + high)/2;
        if(calc(mid) < m) low = mid+1;
        else high = mid;
    }

    LL n = low;
    if(calc(n) == m) cout << n << endl;
    else cout << -1 << endl;

    return 0;
}
