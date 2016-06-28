#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef unsigned long long ULL;

int main()
{
    ULL k, n, odd, even;

    cin >> n >> k;

    odd = ( n & 1 ) ? n/2 + 1 : n/2;
    even = n / 2;

    if( k <= odd )
        cout << 2 * ( k - 1 ) + 1 << endl;
    else
        cout << 2 * ( k - odd ) << endl;

    return 0;
}
