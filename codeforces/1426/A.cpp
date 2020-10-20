#include <bits/stdc++.h>

using namespace std;

void test_case(int kase) {
    int n, x;
    scanf("%d %d", &n, &x);
    
    n--;
    int res = 0;
    if(n > 1) {
        n -= 2;
        res = n/x + 1;
    }
    printf("%d\n", res+1);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++) {
        test_case(kase);
    }
    return 0;
}
