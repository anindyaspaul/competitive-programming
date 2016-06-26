#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

LL binToBase(LL x, LL b)
{
    if(x == 0) return (LL) 0;
    else return b*binToBase(x/2, b) + (x%2);
}

LL findFactor(LL x)
{
    if(x%2 == 0) return 2;
    for(LL d = 3; d*d <= x; d += 2) {
        if(x%d == 0) return d;
    }
    return 0;
}

int main()
{
    freopen("output.txt", "w", stdout);

    cout << "Case #1:" << endl;

    int n = 16, j = 500;

    for(int i = (1<<(n-1))+1; j > 0; i += 2) {
        vector <LL> factors;
        for(int b = 2; b <= 10; b++) {
            LL x = binToBase(i, b);
            LL factor = findFactor(x);
            if(factor) factors.push_back(factor);
            else break;
        }

        if(factors.size() < 9) continue;

        cout << binToBase(i, 10) << binToBase(i, 10);
        for(int k = 0; k < factors.size(); k++) {
            cout << " " << factors[k];
        }
        cout << endl;

        j--;
    }

    return 0;
}
