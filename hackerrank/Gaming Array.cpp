#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int main()
{
    int g;
    cin >> g;
    while(g--) {
        int n;
        cin >> n;
        int prev = INT_MIN;
        int cnt = 0;
        while(n--) {
            int x;
            cin >> x;
            if(x > prev) {
                prev = x;
                cnt++;
            }
        }

        if(cnt&1) cout << "BOB";
        else cout << "ANDY";
        cout << endl;
    }

    return 0;
}
