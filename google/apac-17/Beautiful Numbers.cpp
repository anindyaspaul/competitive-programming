#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

LL oneCnt(LL N, LL b)
{
  LL cnt = 0;
  while(N > 0) {
    LL dig = N%b;
    if(dig == 1) cnt++;
    else return 0;
    N /= b;
  }
  return cnt;
}

int main()
{
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  LL t, cs = 1;
  cin >> t;

  while(t--) {
    LL N;
    cin >> N;

    LL res = 0;
    LL b = N;
    for(LL i = N; i > 1; i--) {
      LL cnt = oneCnt(N, i);
      if(cnt > res) {
        res = cnt;
        b = i;
      }
    }

    cout << "Case #" << cs++ << ": " << b << endl;
  }

  return 0;
}
