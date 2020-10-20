#include <bits/stdc++.h>

using namespace std;

void test_case(int n) {
    unordered_map<long long, bool> set;
    set[0] = true;
    int cnt = 0;
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d\n", &x);
        sum += x;
        if(set.find(sum) != set.end()) {
            cnt++;
            sum = x;
            set.clear();
            set[0] = true;
        }
        set[sum] = true;
    }
    printf("%d\n", cnt);
}

int main() {
    int t;
    scanf("%d", &t);
    test_case(t);
    return 0;
}
