#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define INF 1000000010
#define MAX 100010

vector <LL> vc;

double f(double r)
{
    double ret = 0.0;
    for(LL i = 0; i < vc.size(); i++) {
        double p = pow(1.0+r, vc.size()-i-1);
        if(i == 0) ret -= vc[i]*p;
        else ret += vc[i]*p;
    }
    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int t, cs = 1;
    cin >> t;

    while(t--) {
        LL m;
        cin >> m;

        vc.clear();

        m++;
        while(m--) {
            LL x;
            cin >> x;
            vc.push_back(x);
        }



        printf("Case #%d: %0.10f\n", cs++, f(r));
    }

    return 0;
}
