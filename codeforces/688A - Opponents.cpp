#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int main()
{
    int n, d;
    cin >> n >> d;

    int cnt = 0;
    int mxi = 0;
    for(int i = 0; i < d; i++) {
        string s;
        cin >> s;

        bool f = false;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == '0') {
                f = true;
                break;
            }
        }

        if(f) {
            cnt++;
            mxi = max(mxi, cnt);
        }
        else {
            cnt = 0;
        }
    }

    cout << mxi << endl;

    return 0;
}
