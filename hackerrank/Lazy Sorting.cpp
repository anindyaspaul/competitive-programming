#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define mx 110

int ara[mx];
bool vis[mx];

int main()
{
    int n;
    cin >> n;

    bool done = true;
    for(int i = 0; i < n; i++) {
        cin >> ara[i];
        if(i && ara[i] < ara[i-1])
            done = false;
    }

//    if(done) {
//        cout << "0" << endl;
//        return 0;
//    }

    map <int, int> mp;
    for(int i = 0; i < n; i++) {
        mp[ara[i]]++;
    }

    LL up = 1, down = 1;
    for(int i = 1; i <= n; i++)
        up *= i;

    for(int i = 0; i < n; i++) {
        if(!vis[ara[i]]) {
            vis[ara[i]] = true;
            LL t = 1;
            for(int j = 1; j <= mp[ara[i]]; j++)
                t *= j;
            LL d = __gcd(up, t);
            up /= d;
            t /= d;
            down *= t;

            d = __gcd(up, down);
            up /= d;
            down /= d;
        }
    }

    cout << up << endl;

    return 0;
}

