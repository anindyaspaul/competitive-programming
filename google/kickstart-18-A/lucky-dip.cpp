#include <bits/stdc++.h>

using namespace std;

#define LL long long

int maxi = 0;
vector<int> items;

double calc(int k, double prob) {
    double ret = 0;
    for(int i = 0; i < items.size(); i++) {
        if(k == 0 || items[i] == maxi) ret += items[i] * prob/items.size();
        else ret += calc(k-1, prob/items.size());
//        cout << items[i] << ' ' << ret << endl;
    }
    return ret;
}

int main() {
    freopen("/Users/anindya.paul/Personal/competitive-programming/google/kickstart-18-A/input.txt", "r", stdin);
//    freopen("/Users/anindya.paul/Personal/competitive-programming/google/kickstart-18-A/A-large.out", "w", stdout);

    int t;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++) {
        int n, k;
        scanf("%d %d", &n, &k);

        maxi = 0;
        items.clear();
        for(int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v);
            items.push_back(v);
            maxi = max(maxi, v);
        }
        double res = 0;
        printf("Case #%d: %0.6lf\n", kase, calc(k, 1.0));
    }

    return 0;
}