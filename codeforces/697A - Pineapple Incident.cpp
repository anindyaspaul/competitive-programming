//697
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int main()
{
    LL t, s, x;
    cin >> t >> s >> x;

    if(t == x) {
        cout << "YES" << endl;
        return 0;
    }
    if(x < t) {
        cout << "NO" << endl;
        return 0;
    }

    x -= t;
    if(x >= s && (x%s == 0 || x%s == 1)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
