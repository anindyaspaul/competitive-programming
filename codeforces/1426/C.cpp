#include <bits/stdc++.h>

using namespace std;

void test_case(int kase) {
    int n;
    scanf("%d", &n);
    
    int ans = INT_MAX;
    for(int i = 1; i*i <= n; i++) {
        int moves = i-1;
        moves += ((n-i + i-1)/i);
        ans = min(ans, moves);
    }
    printf("%u\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++) {
        test_case(kase);
    }
    return 0;
}
