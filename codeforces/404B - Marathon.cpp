
#include <stdio.h>


#define EPS 1e-5
// Template ends, coding starts


int main()
{
//    READ( "in.txt" );
//    WRITE( "out.txt" );

    int n;
    double a, d;

    while(scanf("%lf %lf", &a, &d) == 2) {
        scanf("%d", &n);

        int dir = 0;
        double x = 0.0;
        double y = 0.0;
        while(n--) {
            int loop = d/(4*a);
            double left = d - (4*a*loop);
            while(left > EPS) {
                if(dir == 0) {
                    if(left > a-x) {
                        left -= (a-x);
                        x = a;
                        dir++;
                    }
                    else {
                        x += left;
                        left = 0;
                    }
                }
                else if(dir == 1) {
                    if(left > a-y) {
                        left -= (a-y);
                        y = a;
                        dir++;
                    }
                    else {
                        y += left;
                        left = 0;
                    }
                }
                else if(dir == 2) {
                    if(left > x) {
                        left -= x;
                        x = 0;
                        dir++;
                    }
                    else {
                        x -= left;
                        left = 0;
                    }
                }
                else if(dir == 3) {
                    if(left > y) {
                        left -= y;
                        y = 0;
                        dir++;
                    }
                    else {
                        y -= left;
                        left = 0;
                    }
                }
                dir %= 4;
            }

            printf("%0.6lf %0.6lf\n", x, y);
        }
    }

    return 0;
}
