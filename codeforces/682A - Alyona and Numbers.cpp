#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    LL m, n;

    while(cin >> m >> n) {
        LL d1 = m/5;
        LL r1 = m%5;
        LL d2 = n/5;
        LL r2 = n%5;

        LL sum = 0;
        sum += m*d2;
        sum += r2*d1;
        if(r1+r2 >= 5)
            sum += (r1+r2-4);

        cout << sum << endl;
    }

    return 0;
}
