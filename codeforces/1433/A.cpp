#include <bits/stdc++.h>

using namespace std;

void test_case(int kase) {
    int n;
    scanf("%d", &n);
    int count = (n%10-1)*10;
    for(int i = 1; i <= 4; i++) {
        if(n%10) {
            count += i;
            n /= 10;
        }
    }
    printf("%d\n", count);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++) {
        test_case(kase);
    }
    return 0;
}
