#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define mx 110

int ara[mx];

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> ara[i];

    bool done = false;
    while(!done) {
        done = true;
        for(int i = 0, j = 1; i < n-1; i++, j++) {
            if(ara[i] > ara[j]) {
                swap(ara[i], ara[j]);
                cout << i+1 << ' ' << j+1 << endl;
                done = false;
            }
        }
    }

    return 0;
}
