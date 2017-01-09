#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define mx 100010

int main()
{
    int n, x;
    cin >> n >> x;

    vector <int> vc;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        vc.push_back(t);
        mp[t]++;
    }

    LL cnt = 0;
    for(int i = 0; i < vc.size(); i++) {
        int u = vc[i];
        int v = x ^ u;
        if(u == v) cnt += mp[u]-1;
        else if(mp.find(v) != mp.end()) cnt += mp[v];
    }
    cout << cnt/2 << endl;


    return 0;
}
