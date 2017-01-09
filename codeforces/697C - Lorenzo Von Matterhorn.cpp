#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

map <pair<LL, LL>, LL> mp;

LL height(LL x)
{
    LL ret = 0;
    while(x) {
        x /= 2;
        ret++;
    }
    return ret;
}

void update(LL u, LL v, LL w)
{
    LL hu = height(u);
    LL hv = height(v);

    while(hv > hu) {
        pair <LL, LL> pp(v/2, v);
        if(mp[pp] == 0) mp[pp] = w;
        else mp[pp] += w;
        v /= 2;
        hv--;
    }

    while(u != v) {
        pair <LL, LL> pp;

        pp = make_pair(u/2, u);
        if(mp[pp] == 0) mp[pp] = w;
        else mp[pp] += w;
        u /= 2;

        pp = make_pair(v/2, v);
        if(mp[pp] == 0) mp[pp] = w;
        else mp[pp] += w;
        v /= 2;
    }
}

LL query(LL u, LL v)
{
    LL ret = 0;

    LL hu = height(u);
    LL hv = height(v);

    while(hv > hu) {
        pair <LL, LL> pp(v/2, v);
        ret += mp[pp];
        v /= 2;
        hv--;
    }

    while(u != v) {
        pair <LL, LL> pp;

        pp = make_pair(u/2, u);
        ret += mp[pp];
        u /= 2;

        pp = make_pair(v/2, v);
        ret += mp[pp];
        v /= 2;
    }

    return ret;
}

int main()
{
    int q;
    cin >> q;

    while(q--) {
        LL com, u, v, w;
        cin >> com >> u >> v;
        if(u > v) swap(u, v);

        if(com == 1) {
            cin >> w;
            update(u, v, w);
        }
        else {
            cout << query(u, v) << endl;
        }
    }

    return 0;
}
