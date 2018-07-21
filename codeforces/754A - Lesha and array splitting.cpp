#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int main()
{
    int n;
    cin >> n;

    vector <int> vc;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x != 0) vc.push_back(i);
    }

    if(vc.size() == 0) cout << "NO" << endl;
    else {
        cout << vc.size() << endl;
        for(int i = 0; i < vc.size(); i++) {
            
        }
    }

    return 0;
}
