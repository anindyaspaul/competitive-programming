#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define INF 1000000010
#define MAX 30

char str[MAX];

class P {
public:
    string s;
    int cnt;

    P(string a, int b) {
        s = a;
        cnt = b;
    }

    bool operator < (const P& x) const {
        if(cnt != x.cnt) return cnt > x.cnt;
        return s.compare(x.s) < 0;
    }
};

vector <P> vc;

int calc(char *s)
{
    set <char> st;
    for(int i = 0; s[i]; i++) {
        if(s[i] == ' ') continue;
        st.insert(s[i]);
    }
    return st.size();
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t, cs = 1;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        getchar();

        vc.clear();
        for(int i = 0; i < n; i++) {
            gets(str);
            vc.push_back(P(string(str), calc(str)));
        }

        sort(vc.begin(), vc.end());

        cout << "Case #" << cs++ << ": " << vc[0].s << endl;
    }

    return 0;
}
