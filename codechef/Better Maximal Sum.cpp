#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define mx 100005
#define INF 1000000001

LL ara[mx];
vector <int> vc;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        vc.clear();

        LL msum = -INF;
        for(int i = 0; i < n; i++) {
            scanf("%lld", &ara[i]);
            if(msum < ara[i])
                msum = ara[i];
        }

        if(msum <= 0) {
            printf("%lld\n", msum);
            continue;
        }

        msum = 0;
        LL sum = 0;
        int s = 0, e = 0;
        for(int i = 0; i < n; i++) {
            if(sum + ara[i] < 0) {
                vc.push_back(s);
                vc.push_back(e);
                s = e = i+1;
                sum = 0;
            }
            else sum += ara[i];

            if(sum > msum) {
                msum = sum;
                e = i;
            }
        }

        if(e < n) {
            vc.push_back(s);
            vc.push_back(e);
        }

        msum = 0;
        for(int i = 0; i < vc.size(); i += 2) {
            s = vc[i];
            e = vc[i+1];
            sum = 0;
            LL lwst = 0;
            for(int j = s; j <= e; j++) {
                sum += ara[j];
                if(ara[j] < lwst)
                    lwst = ara[j];
            }
            sum -= lwst;
            if(msum < sum)
                msum = sum;
        }

        for(int i = 1; i < vc.size()-2; i += 2) {
            if(vc[i+1]-vc[i] > 1) continue;

            sum = 0;
            for(int j = vc[i-1]; j <= vc[i+2]; j++) {
                if(j == vc[i]+1) continue;
                sum += ara[j];
            }

            if(msum < sum)
                msum = sum;
        }

        printf("%lld\n", msum);
    }

    return 0;
}
