#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int dx[] = {0, +1, +1, +1, 0, -1, -1, -1};
int dy[] = {+1, +1, 0, -1, -1, -1, 0, +1};

int n;
int t[32];

class Entry {
public:
    int a, b, c, d, e;
    Entry(int aa, int bb, int cc, int dd, int ee) {
        a = aa;
        b = bb;
        c = cc;
        d = dd;
        e = ee;
    }
    bool operator<(const Entry &en) const {
        if(a != en.a) return a < en.a;
        if(b != en.b) return b < en.b;
        if(c != en.c) return c < en.c;
        if(d != en.d) return d < en.d;
        return e < en.e;
    }
};

map <Entry, bool> dp;
set <pair<int, int> > st;

void calc(int id, int cnt, int x, int y, int dir)
{
    if(id == n) return;

    Entry e(id, cnt, x, y, dir);
    if(dp.find(e) != dp.end()) return;

    st.insert(make_pair(x, y));

    if(cnt < t[id]) calc(id, cnt+1, x+dx[dir], y+dy[dir], dir);
    else {
        int d1 = dir+1;
        int d2 = dir-1;
        if(d1 == 8) d1 = 0;
        if(d2 == -1) d2 = 7;
        calc(id+1, 1, x+dx[d1], y+dy[d1], d1);
        calc(id+1, 1, x+dx[d2], y+dy[d2], d2);
    }

    dp[e] = true;
    return;
}

int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    calc(0, 1, 0, 0, 0);

    printf("%d\n", st.size());

    return 0;
}
