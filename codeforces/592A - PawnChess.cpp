#include <bits/stdc++.h>

using namespace std;

#define INF 10000

char grid[8][8];

int main()
{
    for(int i = 0; i < 8; i++) {
        scanf("%s", grid[i]);
    }

    int A = INF;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(grid[i][j] == 'W') {
                int cnt = 0;
                for(int k = i-1; k >= 0; k--) {
                    if(grid[k][j] != '.') cnt = INF;
                    else cnt++;
                }
                A = min(A, cnt);
            }
        }
    }

    int B = INF;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(grid[i][j] == 'B') {
                int cnt = 0;
                for(int k = i+1; k < 8; k++) {
                    if(grid[k][j] != '.') cnt = INF;
                    else cnt++;
                }
                B = min(B, cnt);
            }
        }
    }

    if(A <= B) printf("A");
    else printf("B");

    return 0;
}
