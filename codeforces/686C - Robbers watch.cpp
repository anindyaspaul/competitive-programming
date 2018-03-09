#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n, m;

int cntplc(int x)
{
    if(x == 0) return 1;
    int ret = 0;
    while(x) {
        x /= 7;
        ret++;
    }
    return ret;
}

LL pr(int b, int p)
{
    LL ret = 1;
    while(p--) {
        ret *= b;
    }
    return ret;
}

string cat(string s, char ch)
{
    s.push_back(ch);
    return s;
}

map <pair<LL, LL>, LL> dp;

LL calc(int p, LL sp, int q, LL sq, int mask)
{
    if(q == 0) {
        return 1;
    }
    //if(dp[p][q][mask] != -1) return dp[p][q][mask];
    if(dp.find(make_pair(sp, sq)) != dp.end()) return dp[make_pair(sp, sq)];

    LL ret = 0;

    if(p) {
        LL tmp = pr(7, p-1);
        for(int i = 0; i < 7; i++) {
            if(!(mask & (1 << i))) {
                if(sp + i*tmp < n) {
                    ret += calc(p-1, sp + i*tmp, q, sq, mask | (1 << i));
                }
            }
        }
    }
    else {
        LL tmp = pr(7, q-1);
        for(int i = 0; i < 7; i++) {
            if(!(mask & (1 << i))) {
                if(sq + i*tmp < m) {
                    ret += calc(p, sp, q-1, sq + i*tmp, mask | (1 << i));
                }
            }
        }
    }

    //return dp[p][q][mask] = ret;
    return dp[make_pair(sp, sq)] = ret;
}

int main()
{
    cin >> n >> m;

    dp.clear();
    if(cntplc(n-1) + cntplc(m-1) > 7) cout << "0" << endl;
    else cout << calc(cntplc(n-1), 0, cntplc(m-1), 0, 0) << endl;

    return 0;
}
