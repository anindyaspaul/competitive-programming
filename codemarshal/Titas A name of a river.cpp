#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

map <string, int> mp;

int main()
{
    int t, cs = 1;

    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        mp.clear();
        int maxi = -1;
        string out = "";
        while(n--) {
            string s;
            cin >> s;
            if(++mp[s] > maxi) {
                maxi = mp[s];
                out = s;
            }
        }

        cout << "Case " << cs++ << ": " << out << endl;
    }

    return 0;
}
