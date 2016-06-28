#include <iostream>

using namespace std;

int main()
{
    int n, i, j, t, count;

    cin >> t;
    for( i = 1; i <= t; i++ ) {
        cin >> n;

        count = 0;
        for( j = 0; j < 32; j++ ) {
            if( n & ( 1 << j ) )
                count++;
        }

        cout << "Case " << i;
        if( count & 1 )  cout << ": odd\n";
        else cout << ": even\n";
    }

    return 0;
}
