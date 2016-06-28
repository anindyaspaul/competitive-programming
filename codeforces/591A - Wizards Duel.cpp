#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l, p, q;

    while(scanf("%d %d %d", &l, &p, &q) == 3) {
        printf("%0.6lf\n", (double)((double)p*l)/((double)p+q));
    }

    return 0;
}
