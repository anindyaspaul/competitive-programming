#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

queue <LL> nq, mq;

int main()
{
    LL t, n, m, cs = 1;

    scanf("%lld", &t);
    while(t--) {

        scanf("%lld %lld", &n, &m);
        while(n--) {
            LL x;
            scanf("%lld", &x);
            nq.push(x);
        }
        while(m--) {
            LL x;
            scanf("%lld", &x);
            mq.push(x);
        }

        LL out = 0;
        while(true) {
            LL x = 1000000010;
            if(!nq.empty()) x = min(x, nq.front());
            if(!mq.empty()) x = min(x, mq.front());

            if(!nq.empty() && x == nq.front()) nq.pop();
            else if(!mq.empty() && x == mq.front()) mq.pop();

            if(nq.empty() && mq.empty()) break;

            out += x;
        }

        printf("Case %lld: %lld\n", cs++, out);
    }

    return 0;
}
