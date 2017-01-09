#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int i, flag, val;
    int h = 0, t5 = 0, f = 0;

    flag = 0;
    for( i = 0; i < n; i++ ) {
        cin >> val;
        if( flag ) continue;
        if( val == 25 ) {
            t5++;
            continue;
        }
        if( val == 50 ) {
            f++;
            t5--;
            if( t5 < 0 ) flag = 1;
            continue;
        }
        if( val == 100 ) {
            h++;
            if( f ) {
                f--;
                t5--;
                if( t5 < 0 ) flag = 1;
                continue;
            }
            else {
                t5 -= 3;
                if( t5 < 0 ) flag = 1;
                continue;
            }
        }
    }

    if( flag ) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}
