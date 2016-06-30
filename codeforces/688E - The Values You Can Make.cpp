#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define mx 501

int n;
int c[mx];
bool chk[mx][mx][mx];

set <int> st;

void calc(int i, int k, int v)
{
    if(k == 0) {
        st.insert(v);
        return;
    }

    if(i == n) return;

    if(chk[i][k][v]) return;

    if(c[i] <= k) {
        calc(i+1, k-c[i], v+c[i]);
        calc(i+1, k-c[i], v);
    }

    calc(i+1, k, v);

    chk[i][k][v] = true;
}

int main()
{
    int k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }

    calc(0, k, 0);

    cout << st.size() << endl;
    for(auto i : st) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
