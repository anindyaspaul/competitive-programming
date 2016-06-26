#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define MOD 1000000007

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t, cs = 1;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        LL res = 1;
        for(int i = 0; i < s.size(); i++) {
            set <char> st;
            if(i > 0) {
                st.insert(s[i-1]);
            }
            if(i < s.size()-1) {
                st.insert(s[i+1]);
            }
            st.insert(s[i]);
            res *= st.size();
            res %= (LL) MOD;
        }

        cout << "Case #" << cs++ << ": " << res << endl;
    }

    return 0;
}
