#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

vector <int> imp;

int main()
{
    int n, k;
    cin >> n >> k;

    int sum = 0;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if(!b) sum += a;
        else imp.push_back(a);
    }

    sort(imp.begin(), imp.end());

    for(int i = imp.size()-1; i >= 0; i--) {
        if(k) {
            sum += imp[i];
            k--;
        }
        else sum -= imp[i];
    }

    cout << sum << endl;

    return 0;
}
