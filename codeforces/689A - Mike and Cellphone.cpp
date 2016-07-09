//689
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

vector <pair<int, int> > pos = { {3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
vector <pair<int, int> > path;

bool findpath(int i, int x, int y)
{
//    cout << x << ' ' << y << endl;
    if(x < 0 || y < 0) return false;
    if(x > 3 || y > 2) return false;
    if(x == 3 && y == 0) return false;
    if(x == 3 && y == 2) return false;
    if(i == path.size()) return true;


    return findpath(i+1, x+path[i].first, y+path[i].second);
}

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    for(int i = 1; i < n; i++) {
        int u = s[i-1]-'0';
        int v = s[i]  -'0';

        path.push_back(make_pair(pos[v].first-pos[u].first, pos[v].second-pos[u].second));
    }

    bool f = false;
    for(int i = 0; i < 10; i++) {
        if(i == (s[0]-'0')) continue;
//        cout << endl;
        if(findpath(0, pos[i].first, pos[i].second)) {
            f = true;
        }
    }

    if(f) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}
