#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define MX 1000010

bool f[MX];

vector <int> primes;

void genPrime()
{
    f[0] = true;
    f[1] = true;
    for(int i = 4; i < MX; i += 2)
        f[i] = true;
    for(int i = 3; i*i < MX; i += 2) {
        if(!f[i]) {
            for(int j = i+i; j < MX; j += i)
                f[j] = true;
        }
    }

    primes.push_back(2);
    for(int i = 3; i < MX; i += 2)
        if(!f[i])
            primes.push_back(i);
}

int main()
{
    genPrime();

    int t;
    scanf("%d", &t);

    while(t--) {
        LL n;
        scanf("%lld", &n);

        LL out = n;
        for(int i = 0; i < primes.size() && primes[i]*primes[i] <= n; i++) {
            if(n%primes[i] == 0)
                out = primes[i];
        }

        printf("%lld\n", out);
    }

    return 0;
}
