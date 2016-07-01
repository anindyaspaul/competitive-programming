#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > E;

namespace std {
    bool operator<(const pair<int,int> &u, const pair<int,int> &v)
    {
        if(u.first == v.first) return u.second > 0;
        return u.first < v.first;
    }
}

vector <int> vc;

int main()
{

    E.push_back(make_pair(0, 1));
    E.push_back(make_pair(0, -1));

    sort(E.begin(), E.end());

    for(auto x : E)
        cout << x.first << " " << x.second << endl;

    vc.push_back(1);
    vc.push_back(0);

    sort(vc.begin(), vc.end());

    for(auto x: vc)
        cout << x << endl;

    return 0;
}
