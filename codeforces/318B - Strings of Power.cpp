#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef unsigned long long ULL;

char str[10000000];

int main()
{
    ULL count = 0, add = 0, i = 0;

    gets( str );

    for( i = 0; str[i]; i++ ) {

        if( !strncmp( &str[i], "heavy", 5 ) ) {
            add++;
            i += 4;
        }
        else if( !strncmp( &str[i], "metal", 5 ) ) {
            count += add;
            i += 4;
        }
    }

    cout << count << endl;

    return 0;
}
