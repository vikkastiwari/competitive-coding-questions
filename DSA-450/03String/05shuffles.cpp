// question link: https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings

#include <bits/stdc++.h>
using namespace std;
// strings should be distinct
int checkValidShuffle(string s1, string s2, string shuffle)
{
    if (s1.length() + s2.length() != shuffle.length())
        return 0;
    int i = 0, j = 0, k = 0;
    while (k != shuffle.length())
    {
        if (i < s1.length() && s1[i] == shuffle[k])
        {
            i++;
        }
        else if (j < s2.length() && s2[j] == shuffle[k])
        {
            j++;
        }
        else
        {
            return 0;
        }
        k++;
    }
    if (i < s1.length() || j < s2.length())
    {
        return 0;
    }
    return 1;
}

int main()
{
    string s1 = "XY";
    string s2 = "12";
    string shuffle = "X1Y2";
    cout << checkValidShuffle(s1, s2, shuffle) << endl;
    return 0;
}
