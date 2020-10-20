#include <bits/stdc++.h>

using namespace std;

void test_case(int kase) {
    int n, m;
    int tr, bl, tmp;
    scanf("%d %d", &n, &m);
    bool flag = false;
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &tmp, &tr);
        scanf("%d %d", &bl, &tmp);
        if(tr == bl) flag = true;
    }
    if(m%2 == 1) flag = false;

    if(flag)
        printf("YES\n");
    else
        printf("NO\n");

}

int main() {
    int t;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++) {
        test_case(kase);
    }
    return 0;
}
