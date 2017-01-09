#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int main()
{
    int n;
    cin >> n;

    bool f = true;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        int d;
        string s;
        cin >> d >> s;
        if(s.compare("East") == 0 || s.compare("West") == 0) {
            if(cur == 0 || cur == 20000) f = false;
            continue;
        }
        else if(s.compare("North") == 0) {
            if(d > cur) f = false;
            else cur -= d;
        }
        else {
            if(cur + d > 20000) f = false;
            else cur += d;
        }
    }

    if(f && cur == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
