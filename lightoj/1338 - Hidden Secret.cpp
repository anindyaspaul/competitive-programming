#include<bits/stdc++.h>
using namespace std;
int main(){

    string a, b;
    vector<int> x, y;
    int i, k, t;

    cin >> t;
getchar();
    for (int j = 0; j < t; j++)
    {
        x.clear(); y.clear();
        bool same = true;
        getline(cin, a);
        getline(cin, b);



        for (i = 0; i < a.length(); i++){
            k = (int)a[i];
            if (k <= 90 && k >= 65) k += 32;
            if (k != 32)    x.push_back(k);
        }
        for (i = 0; i < b.length(); i++){
            k = (int)b[i];
            if (k <= 90 && k >= 65) k += 32;
            if (k != 32)    y.push_back(k);
        }
        if (x.size() != y.size())   printf("Case %d: No\n", j + 1);
        else{
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());

            for (i = 0; i < x.size(); i++){
                if (x[i] != y[i]){
                    same = false;
                    break;
                }
            }
            if (same)    printf("Case %d: Yes\n", j + 1);
            else printf("Case %d: No\n", j + 1);
        }
    }

}
