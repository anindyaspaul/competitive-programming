#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define mx 100010

int main()
{
    vector <int> vc;

    int n = 5;

    for(int i = 1; i <= n; i++) {
        vc.push_back(i);
        cout << i;
    }
    cout << endl;

    while(next_permutation(vc.begin(), vc.end())) {
        for(int i = 0; i < n; i++) {
            cout << vc[i];
        }
        cout << endl;
    }

    return 0;
}
