#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define MX 1000

char str[MX];
char rev[MX];

int main()
{
    scanf("%s", str);

    int i = 0;
    for( ; str[i] != 'e'; i++) {
        rev[i] = str[i];
        rev[i+1] = 0;
    }

    int p = atoi(str+i+1);

    i = 0;
    while(rev[i] != '.') i++;

    while(p--) {
        if(rev[i+1] == 0) {
            rev[i+1] = '0';
            rev[i+2] = 0;
        }

        swap(rev[i], rev[i+1]);
        i++;
    }

    bool gg = false;
    int cntgg = 0;
    int pos = 0;
    int len = strlen(rev);
    for(int i = 0; i < len; i++) {
        if(gg && rev[i] != '0') cntgg++;
        if(rev[i] == '.') {
            gg = true;
            pos = i;
        }
    }
    if(cntgg == 0) rev[pos] = 0;

    gg = false;
    for(int i = 0; i < len; i++) {
        if((rev[i] == '0' && rev[i+1] == '.') || rev[i] != '0') {
            strcpy(str, rev+i);
            break;
        }
    }
    if(strlen(str) == 0) strcpy(str, "0");
    puts(str);

    return 0;
}
