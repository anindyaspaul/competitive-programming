#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int main()
{
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  LL t, cs = 1;
  cin >> t;

  while(t--) {
    string s;
    cin >> s;
    LL len = s.size();
    LL i, j;
    cin >> i >> j;
    i--;
    j--;

    LL x = i/len + 1;
    LL y = j/len;
    LL cnt = 0;
    for(LL k = 0; k < s.size(); k++) {
      if(s[k] == 'B') {
        cnt++;
      }
    }

    LL res = (y-x)*cnt;
    x = i%len;
    y = j%len;
    for(LL k = x; k < len; k++) {
      if(s[k] == 'B') {
        res++;
      }
    }
    for(LL k = y; k >= 0; k--) {
      if(s[k] == 'B') {
        res++;
      }
    }

    cout << "Case #" << cs++ << ": " << res << endl;
  }

  return 0;
}
