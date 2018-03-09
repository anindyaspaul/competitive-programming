#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int main()
{
    int q, a, b, c;

    cin >> q;
    while(q--) {
        cin >> a >> b >> c;
        if(abs(c-a) < abs(c-b)) cout << "Cat A";
        else if(abs(c-a) > abs(c-b)) cout << "Cat B";
        else cout << "Mouse C";
        cout << endl;
    }

    return 0;
}
