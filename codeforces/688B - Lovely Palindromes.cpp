#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int main()
{
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        printf("%c", s[i]);
    }
    for(int i = s.size()-1; i >= 0; i--) {
        printf("%c", s[i]);
    }
    puts("");

    return 0;
}
