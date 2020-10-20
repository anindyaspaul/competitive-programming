#include <bits/stdc++.h>

using namespace std;

void test_case(int kase) {
    int n;
    scanf("%d", &n);
    
    int mxi = -1;
    int mxv = -1;
    int mnv = INT_MAX;
    int ara[300010];
    for(int i = 0; i < n; i++) {
        scanf("%d", &ara[i]);
        mxv = max(mxv, ara[i]);
        mnv = min(mnv, ara[i]);
    }
    for(int i = 0; i < n; i++) {
        if(ara[i] != mxv) continue;
        if(i > 0 && ara[i-1] < mxv) mxi = i+1;
        if(i < n-1 && ara[i+1] < mxv) mxi = i+1;
    }
    printf("%d\n", mxi);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++) {
        test_case(kase);
    }
    return 0;
}
