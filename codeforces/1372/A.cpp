#include <bits/stdc++.h>

using namespace std;

void test_case(int kase) {
    int n;
    scanf("%d", &n);
:
    printf("1");
    for(int i = 1; i < n; i++) {
        printf(" 1");
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++)
        test_case(kase);
    return 0;
}
