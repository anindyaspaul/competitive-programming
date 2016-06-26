#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define mx 110

char str[mx];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, cs = 1;
    scanf("%d", &t);

    while(t--) {
        scanf("%s", str);

        int cnt = 0;
        char prev = '0';
        for(int i = 0; str[i]; i++) {
            if(str[i] != prev) cnt++;
            prev = str[i];
        }

        if(str[strlen(str)-1] == '+') cnt--;

        printf("Case #%d: %d\n", cs++, cnt);
    }

    return 0;
}
