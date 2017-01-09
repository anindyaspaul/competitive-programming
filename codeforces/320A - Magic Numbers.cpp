
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <bitset>

#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

using namespace std;

#define EPS 1e-9
#define INF 2147483647
#define PI 3.14159265358979323846264338327950

#define MEM( x, y ) memset( x, y, sizeof( x ) )
#define READ( file ) freopen( file, "r", stdin )
#define WRITE( file ) freopen( file, "w", stdout )

typedef long long LL;
typedef unsigned long long ULL;

template <class T> T GCD( T x, T y ) { if( x > y ) swap( x, y ); while( y % x != 0 ) { T tmp = x; x = y % x; y = tmp; } return x; }

/// Template ends, coding starts

int main()
{
    char str[12];
    LL i;

    gets( str );

    for( i = 0; str[i]; i++ ) {
        if( !strncmp( &str[i], "144", 3 ) ) {
            i += 2;
        }
        else if( !strncmp( &str[i], "14", 2 ) ) {
            i += 1;
        }
        else if( str[i] != '1' ) {
            break;
        }
    }

    if( i == strlen( str ) ) printf( "YES\n" );
    else printf( "NO\n" );

    return 0;
}

/*   _______________________________________________________________
    |                   _______  _______  _______                   |
    |         |\     /|(  ___  )(  ____ )(  ____ )|\     /|         |
    |         | )   ( || (   ) || (    )|| (    )|( \   / )         |
    |         | (___) || (___) || (____)|| (____)| \ (_) /          |
    |         |  ___  ||  ___  ||  _____)|  _____)  \   /           |
    |         | (   ) || (   ) || (      | (         ) (            |
    |         | )   ( || )   ( || )      | )         | |            |
    |         |/     \||/     \||/       |/          \_/            |
    |                                                               |
    |    _______  _______  ______  _________ _        _______  _    |
    |   (  ____ \(  ___  )(  __  \ \__   __/( (    /|(  ____ \( )   |
    |   | (    \/| (   ) || (  \  )   ) (   |  \  ( || (    \/| |   |
    |   | |      | |   | || |   ) |   | |   |   \ | || |      | |   |
    |   | |      | |   | || |   | |   | |   | (\ \) || | ____ | |   |
    |   | |      | |   | || |   ) |   | |   | | \   || | \_  )(_)   |
    |   | (____/\| (___) || (__/  )___) (___| )  \  || (___) | _    |
    |   (_______/(_______)(______/ \_______/|/    )_)(_______)(_)   |
    |_______________________________________________________________|
*/
