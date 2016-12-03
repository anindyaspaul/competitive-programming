#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

map <pair <LL, LL>, LL> dp;

LL lim;

LL calc(LL prev, LL rem)
{
  if(rem == 0) return 1;
  if(rem < prev) return 0;

  pair <LL, LL> pp = make_pair(prev, rem);
  if(dp.find(pp) != dp.end()) {
    return dp[pp];
  }

  LL ret = 0;
  for(LL i = prev; i <= lim; i++) {
    ret += calc(i, rem-i);
  }

  return dp[pp] = ret;
}

int main()
{
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  LL t, cs = 1;
  cin >> t;

  while(t--) {
    LL n, d;
    cin >> n >> d;

    dp.clear();
    LL cnt = 0;
    for(LL i = d; i <= n; i += d) {
      lim = i+2;
      cnt += calc(i, n-i);
    }

    cout << "Case #" << cs++ << ": " << cnt << endl;
  }

  return 0;
}
