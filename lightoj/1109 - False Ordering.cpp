#include <bits/stdc++.h>

using namespace std;

#define mx 1001

class Div {
public:
    int value;
    int cnt;

    bool operator < (const Div& p) const
    {
        if(cnt != p.cnt) return cnt < p.cnt;
        else return value > p.value;
    }
};

vector <Div> pos(mx);

void gen()
{
    for(int i = 0; i < mx; i++) {
        pos[i].value = i;
        pos[i].cnt = 1;
    }

    pos[0].cnt = 0;
    for(int i = 2; i < mx; i++) {
        for(int j = i; j < mx; j += i) {
            pos[j].cnt++;
        }
    }

    sort(pos.begin(), pos.end());
}

int main()
{
    int n, t, cs = 1;

    gen();

    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("Case %d: %d\n", cs++, pos[n].value);
    }

    return 0;
}
