#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int main()
{
    int x1, v1, x2, v2;

    cin >> x1 >> v1 >> x2 >> v2;

    if(v1 <= v2)
        cout << "NO" << endl;
    else {
        int dx = x2-x1;
        int dv = v1-v2;
        if(dx%dv == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
