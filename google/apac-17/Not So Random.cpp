#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define MOD 1000000007
#define MX 1010

int ara[4][MX];
double a, b, c;
int k;

double calc(int n, int x)
{
    if(n == 0) return x;

    double ret = 0;
    ret += a/100 * calc(n-1, x&k);
    ret += b/100 * calc(n-1, x|k);
    ret += c/100 * calc(n-1, x^k);

    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t, cs = 1;
    cin >> t;

    while(t--) {
        int n, x;
        scanf("%d %d %d %lf %lf %lf", &n, &x, &k, &a, &b, &c);

        printf("Case #%d: %0.10lf\n", cs++, calc(n, x));
    }

    return 0;
}
