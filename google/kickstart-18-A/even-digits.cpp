//
// Created by anindya.paul on 3/18/18.
//

#include <bits/stdc++.h>

using namespace std;

#define LL long long

LL up(LL n) {
    for(LL mod = 1; mod <= n; mod *= 10) {
        if((n/mod)%2) {
            n += mod;
            n -= (n%mod);
        }
    }
    return n;
}

LL down(LL n) {
    LL filler = 8888888888888888L;
    for(LL mod = 1; mod <= n; mod *= 10) {
        if((n/mod)%2) {
            n -= mod;
            n = (n/mod)*mod;
            n += filler%mod;
        }
    }
    return n;
}

int main() {
    freopen("/Users/anindya.paul/Personal/competitive-programming/google/kickstart-18-A/A-large.in", "r", stdin);
    freopen("/Users/anindya.paul/Personal/competitive-programming/google/kickstart-18-A/A-large.out", "w", stdout);

    int t;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++) {
        LL N;
        scanf("%lld", &N);
        printf("Case #%d: %lld\n", kase, min(up(N)-N, N-down(N)));
    }

    return 0;
}
