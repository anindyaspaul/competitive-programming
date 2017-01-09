#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define EPS 1e-6

int main()
{
    freopen("progress_pie.txt", "r", stdin);
    freopen("progress_pie_out.txt", "w", stdout);

    int t;
    cin >> t;

    for(int cs = 1; cs <= t; cs++) {
        double p, x, y;
        cin >> p >> x >> y;

        x -= 50.0;
        y -= 50.0;

        cout << "Case #" << cs << ": ";

        if(x*x+y*y > 2500.0) {
            cout << "white" << endl;
            continue;
        }

        double theta = acos((50.0*y)/(50.0*sqrt(x*x+y*y)));

        if(x < 0.0) theta = 2*M_PI - theta;
        if(theta <= p*2*M_PI/100.0) cout << "black" << endl;
        else cout << "white" << endl;
    }

    return 0;
}
