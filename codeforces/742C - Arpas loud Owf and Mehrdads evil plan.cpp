#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define mx 110

int crush[mx];
int vis[mx];
int len;
bool flag;

LL lcm(int a, int b)
{
    if(b > a) swap(a, b);
    return a/__gcd(a, b) * b;
}

void dfs(int s) {
    vis[s]++;
    if(vis[s] == 2) return;

    len++;
    dfs(crush[s]);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> crush[i];
    }

    LL t = 1;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            len = 0;
            dfs(i);

            if(vis[i] != 2) {
                flag = true;
                break;
            }

            if(len&1) t = lcm(t, len);
            else t = lcm(t, len/2);
        }
    }

    if(flag) cout << -1 << endl;
    else cout << t << endl;

    return 0;
}
