#include<bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(NULL));

    long long cnt = 100000;
    long long L = 100000;
    long long avg = 0;
    for(int i = 0; i < cnt; i++) {
        long long x = rand()*L /RAND_MAX;
        long long y = rand()*L /RAND_MAX;
        avg += abs(x-y);
    }
    avg /= cnt;
    cout << "Average: " << avg << endl;

    return 0;
}
