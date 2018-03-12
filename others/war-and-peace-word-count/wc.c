#include <stdio.h>
#include <stdlib.h>

inline int isnotspace(char ch)
{
    if(ch == ' ') return 0;
    if(ch == '\n') return 0;
    if(ch == '\t') return 0;
    if(ch == '\r') return 0;
    // if(ch == '\v') return 0;
    return 1;
}

int main(int argc, char** argv)
{
    FILE* fp = fopen(argv[1], "r");

    // fseek(fp, 0, SEEK_END);
    // long long sz = ftell(fp);
    long long sz = 1128807120;
    // printf("Size: %lld\n", sz);
    // fseek(fp, 0, SEEK_SET);

    char* str = (char*) malloc(sz+1);
    fread(str, sz, 1, fp);
    str[sz] = 0;
    printf("File loaded.\n");

    long long count = 0;

    int flag = 0;
    for(int i = 0; i < sz; i++) {
        if(isnotspace(str[i])) {
            if(!flag) {
                flag = 1;
                count++;
            }
        }
        else {
            flag = 0;
        }
    }

    // wc -w wap.txt
    // 190280832
    printf("Word count: %lld\n", count);

    return 0;
}
