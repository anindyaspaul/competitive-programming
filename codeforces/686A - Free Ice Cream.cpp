#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    LL n, x;

    cin >> n >> x;
    LL cnt = 0;
    while(n--) {
        char ch;
        LL d;
        cin >> ch >> d;
        if(ch == '+') x += d;
        else {
            if(x >= d) x -= d;
            else cnt++;
        }
    }

    cout << x << ' ' << cnt << endl;

    return 0;
}
