#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char str[10], temp;
    long long i, flag[200] = { 0 }, ans = 1, used = 0;

    gets( str );

    for( i = 0; str[i]; i++ ) {

        if( str[i] == '?' ) {
            if( i == 0 ) ans *= 9;
            else ans *= 10;
        }

        if( str[i] >= 'A' && str[i] <= 'Z' ) {
            temp = str[i];
            if( !flag[ temp ] ) {
                if( i == 0 ) ans *= 9;
                else ans *= ( 10 - used );
                flag[ temp ] = 1;
                used++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
