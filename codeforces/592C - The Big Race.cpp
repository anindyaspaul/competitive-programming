#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

int main()
{
    ULL t, w, b;

    cin >> t >> w >> b;

    if(w < b) swap(w, b);

    ULL gcd = __gcd(w, b);

    ULL tw = w/gcd;

    ULL lcm = tw*b;

    ULL ans = 0;

    if(lcm/tw == b) { // no overflow

        ans = (t/lcm) * (min(w, b));

        ULL tmp = (t/lcm)*lcm;

        ans += min(min(w, b)-1, t-tmp);
    }
    else {
        ans = min(min(w, b)-1, t);
    }

    ULL div = __gcd(ans, t);

    ans /= div;
    t /= div;

    cout << ans << "/" << t << endl;

    return 0;
}
