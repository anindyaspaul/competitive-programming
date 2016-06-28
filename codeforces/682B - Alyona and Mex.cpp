#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector <int> vc;

int main()
{
    int n;

    scanf("%d", &n);

    vc.clear();
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        vc.push_back(x);
    }

    sort(vc.begin(), vc.end());

    int mini = 1;
    for(int i = 0; i < n; i++) {
        if(vc[i] >= mini) {
            mini++;
        }
    }

    printf("%d\n", mini);

    return 0;
}
