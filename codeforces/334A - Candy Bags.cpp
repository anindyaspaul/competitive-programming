#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

bool vis[10010];

int main()
{
    int n;
    cin >> n;

    int left = 1;
    int right = n*n;
    for(int i = 0; i < n; i++) {
        int tmp = n/2;
        while(tmp--) {
            cout << left << " " << right << " ";
            left++;
            right--;
        }
        cout << endl;
    }

    return 0;
}
