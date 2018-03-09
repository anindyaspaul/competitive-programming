#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define MX 100010
#define INF 1000000010

int ara[MX];
char str[MX];
vector <int> pos;

int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        scanf("%s", str);

        pos.clear();
        for(int i = 0; i < n; i++) {
            scanf("%d", &ara[i]);
            if(str[i] == '1') pos.push_back(i);
        }

        int sum = 0;
        for(int i = 0; i < pos.size()-1; i++) {
            int a = pos[i];
            int b = pos[i+1];

            int mini = INF;
            for(int j = a; j < b; j++) {
                mini = min(mini, ara[j]-ara[a] + ara[b]-ara[j+1]);
            }
            sum += mini;
        }

        sum += ara[pos[0]]-ara[0];
        sum += ara[n-1]-ara[pos[pos.size()-1]];

        printf("%d\n", sum);
    }

    return 0;
}
