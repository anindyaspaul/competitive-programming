#include <bits/stdc++.h>

using namespace std;

string lps(string s)
{
    /* Augment the string.
     * $ is the first char, @ is the last char.
     * Insert # in between every pair of chars.
     */
    string aug = "";
    aug += "$#";
    for(int i = 0; i < s.size(); i++) {
        aug += s[i];
        aug += "#";
    }
    aug += "@";

    // pal[i] = number of palindromic chars on each side of ith char
    vector <int> pal(aug.size(), 0);

    /* C = center of the working palindrome.
     * R = right boundary of the working palindrome.
     * mx = maximum palindrome length.
     * idx = center of the maximum palindrome.
     */
    int C = 0;
    int R = 0;
    int mx = -1;
    int idx = -1;
    for(int i = 1; i < aug.size()-1; i++) {
        // mirr = mirror position of the ith character around C
        int mirr = 2*C - i;
        // if i sits within the boundary
        if(i < R) pal[i] = min(pal[mirr], R-i);
        // Expand beyond known palindrome, i+pal[i]
        while(aug[i + (pal[i]+1)] == aug[i - (pal[i]+1)]) {
            pal[i]++;
        }
        // Update working palindrome
        if(i + pal[i] > R) {
            C = i;
            R = i + pal[i];
        }
        // Save the max palindrome center
        if(pal[i] > mx) {
            mx = pal[i];
            idx = i;
        }
    }

    // Retrieve palindrome from the augmented string
    string ret = "";
    for(int i = idx-pal[idx]; i <= idx+pal[idx]; i++) {
        if(aug[i] != '#') ret += aug[i];
    }

    return ret;
}

int main()
{
    string s;
    cout << "Enter string: ";
    cin >> s;
    cout << "Longest palindromic substring: " << lps(s) << endl;
}
