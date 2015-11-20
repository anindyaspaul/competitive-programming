// Algorithm: Ad-hoc, Sliding Window
// Verdict  : AC

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define MX 1500010

LL ss[MX], tt[MX], aa[MX];

int main()
{
        int t;
        scanf("%d", &t);

        while(t--) {
                int n;
                LL m;
		scanf("%lld %lld %d %lld", &ss[0], &tt[0], &n, &m);

                int ans = n;
                LL sum = 0;
                int i = 1, j = 1;
                for( ; j <= n; j++) {
                        ss[j] = (78901 + 31*ss[j-1]) % 699037;
                        tt[j] = (23456 + 64*tt[j-1]) % 2097151;
                        aa[j] = (ss[j] % 100 + 1) * (tt[j] % 100 + 1);

                        if(sum + aa[j] > m) {
                                ans = min(ans, j-i);
                                sum -= aa[i];
                                i++;
                                j--;
                        } else sum += aa[j];
                }
                ans = min(ans, j-i);

                printf("%d\n", ans);
        }

        return 0;
}
