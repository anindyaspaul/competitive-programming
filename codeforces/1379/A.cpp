#include <bits/stdc++.h>

using namespace std;

void test_case(int kase) {
    int n;
    scanf("%d", &n);

    int l;
    scanf("%d", &l);

    char str[52];
    scanf("%s", str);

    char q[] = "abacaba";
    int lq = 7;


    // Count possible number of query
    // Then count removable number of query
    // If possible - removable <= 1 then yes
    
    int fixed = 0;
    int possible = 0;
    for(int i = 0; i < l-lq; i++) {
        int j = 0;
        bool flag = false;
        for(; j < lenq; j++) {
            
        }
    }
    printf("%s\n", str);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++) {
        test_case(kase);
    }
    return 0;
}
