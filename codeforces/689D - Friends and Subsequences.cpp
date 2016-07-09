#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define INF 1000000010
#define MX 200002


int araa[MX];
int arab[MX];
pair <int, int> tree[4*MX];

// pair first arab min, second araa max

void build(int nd, int s, int e)
{
    if(s == e) {
        tree[nd] = make_pair(arab[s], araa[s]);
        return;
    }

    int left = 2*nd;
    int right = left+1;
    int mid = (s+e)/2;

    build(left, s, mid);
    build(right, mid+1, e);
    tree[nd] = make_pair(min(tree[left].first, tree[right].first),
                         max(tree[left].second, tree[right].second));
}
/*
int minQuery(int nd, int s, int e, int l, int r)
{
    if(l > e || r < s) return INF;
    if(s >= l && e <= r) return tree[0][nd];

    int left = 2*nd;
    int right = left+1;
    int mid = (s+e)/2;

    int a = minQuery(left, s, mid, l, r);
    int b = minQuery(right, mid+1, e, l, r);
    return min(a, b);
}

int maxQuery(int nd, int s, int e, int l, int r)
{
    if(l > e || r < s) return -INF;
    if(s >= l && e <= r) return tree[1][nd];

    int left = 2*nd;
    int right = left+1;
    int mid = (s+e)/2;

    int a = maxQuery(left, s, mid, l, r);
    int b = maxQuery(right, mid+1, e, l, r);
    return max(a, b);
}
*/
pair <int, int> query(int nd, int s, int e, int l, int r)
{
    if(l > e || r < s) return make_pair(INF, -INF);
    if(s >= l && e <= r) return tree[nd];

    int left = 2*nd;
    int right = left+1;
    int mid = (s+e)/2;

    pair <int, int> a = query(left, s, mid, l, r);
    pair <int, int> b = query(right, mid+1, e, l, r);
    return make_pair(min(a.first, b.first), max(a.second, b.second));
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &araa[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &arab[i]);
    }

    build(1, 0, n-1);

    LL cnt = 0;
    for(int l = 0; l < n; l++) {
        int low = l;
        int high = n;
        while(low < high) {
            int mid = (low+high)/2;
            pair <int, int> ret = query(1, 0, n-1, l, mid);
            int mini = ret.first;
            int maxi = ret.second;
            if(maxi < mini) low = mid+1;
            else high = mid;
        }
        int r1 = low;

        low = l;
        high = n;
        while(low < high) {
            int mid = (low+high)/2;
            pair <int, int> ret = query(1, 0, n-1, l, mid);
            int mini = ret.first;
            int maxi = ret.second;
            if(maxi <= mini) low = mid+1;
            else high = mid;
        }
        int r2 = low-1;

        pair <int, int> ret = query(1, 0, n-1, l, r1);
        if(ret.first == ret.second) cnt += (LL) r2-r1+1;
    }

    printf("%I64d\n", cnt);

    return 0;
}
