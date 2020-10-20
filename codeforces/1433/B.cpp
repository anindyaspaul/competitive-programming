#include <bits/stdc++.h>

using namespace std;

int pos[50];


void test_case(int kase) {
    int n;
    scanf("%d", &n);

    int l = 51;
    int r = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &pos[i]);
        if(pos[i]) {
            l = min(l, i);
            r = max(r, i);
        }
    }

    int moves = 0;
    for(int i = l; i <= r; i++) {
        if(pos[i] == 0) {
            moves++;
        }
    }

    printf("%d\n", moves);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++) {
        test_case(kase);
    }
    return 0;
}
