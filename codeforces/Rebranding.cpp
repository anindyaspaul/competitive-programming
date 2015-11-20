#include <bits/stdc++.h>

using namespace std;

#define mx 200010

int rep[30];

int main()
{
    int n, m;

    char str[mx];
    while(scanf("%d %d", &n, &m) == 2) {
        scanf("%s", str);

        for(int i = 0; i < 26; i++) {
            rep[i] = i;
        }

        char a[3], b[3];
        while(m--) {
            scanf("%s %s", a, b);
            char c1 = a[0], c2 = b[0];

            for(int i = 0; i < 26; i++) {
                if(rep[i] == c1-'a') {
                    rep[i] = c2-'a';
                }
                else if(rep[i] == c2-'a') {
                    rep[i] = c1-'a';
                }
            }
        }

        for(int i = 0; i < n; i++) {
            str[i] = rep[str[i]-'a']+'a';
        }

        puts(str);
    }

    return 0;
}
