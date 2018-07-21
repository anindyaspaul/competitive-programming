#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int main()
{
    vector <int> rt, dv;

    int n;
    cin >> n;

    bool imp = false;
    int rating = INT_MAX;
    for(int i = 0; i < n; i++) {
        int c, d;
        cin >> c >> d;
        rt.push_back(c);
        dv.push_back(d);
        if(i == 0) {
            if(d == 2) rating = 1899;
            continue;
        }

        if(d == 1) {
            if(dv[i-1] == 1) {
                if(rating == INT_MAX) continue;
                else rating += rt[i-1];
            }
            else if(dv[i-1] == 2) {
                if(rt[i-1] <= 0 || rating+rt[i-1] < 1900) {
                    imp = true;
                }
                else rating += rt[i-1];
            }
        }
        else if(d == 2) {
            if(dv[i-1] == 1) {
                if(rt[i-1] >= 0) {
                    imp = true;
                }
                else rating = min(rating+rt[i-1], 1899);
            }
            else if(dv[i-1] == 2) {
                rating = min(rating+rt[i-1], 1899);
            }
        }
    }

    if(rating == INT_MAX) {
        if(imp) cout << "Impossible" << endl;
        else cout << "Infinity" << endl;
        return 0;
    }

    rating += rt[n-1];

    int tmp = rating;
    for(int i = n-1; i >= 0; i--) {
        tmp -= rt[i];
        if((dv[i] == 1 && tmp < 1900) || (dv[i] == 2 && tmp >= 1900)) {
            imp = true;
            break;
        }
    }

    if(imp) cout << "Impossible" << endl;
    else cout << rating << endl;


    return 0;
}
