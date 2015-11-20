#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;

    scanf("%I64d", &n);

    printf("%I64d\n", (n-2)*n - 2 - 2*(n-3));

    return 0;
}
