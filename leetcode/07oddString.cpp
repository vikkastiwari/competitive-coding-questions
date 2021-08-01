// question link: https://leetcode.com/problems/largest-odd-number-in-string/

#include <bits/stdc++.h>
using namespace std;

/*
// for large values stoi shows out of range error
class Solution {
public:
    string largestOddNumber(string num) {
        long long n = stoi(num);
        vector<long> odd;
        odd.push_back(n);
        while(n>0){
            int x = n%10;
            if(find(odd.begin(), odd.end(),n) == odd.end() and n!=0){
                odd.push_back(x);
            }
            n = n / 10;
            if(find(odd.begin(), odd.end(),n) == odd.end() and n!=0){
                odd.push_back(n);
            }
        }
        int max=0;
        for(int i=0;i<odd.size();i++){
            int curr = odd[i];
            if(odd[i]%2 !=0){
                if(curr>max){
                    max=curr;
                }
            };
        }
        if(max==0){
            return "";
        }
        return to_string(max);
    }
};

*/

string largestOddNumber(string num)
{
    for (int i = num.size() - 1; i >= 0; --i)
        // num[i] - '0' gives us the integer form of that char
        // eg: '5' -> 5
        // when we do AND operation on it with 1 we come to know whether it is even or odd
        // 1 -> odd
        // 0 -> even
        if ((num[i] - '0') & 1)
        {
            cout << ((num[i] - '0')) << endl;
            // we traverse from back coz we want the max odd number
            // so the substr function returns the substring of that odd number
            return num.substr(0, i + 1);
        }
    return "";
}

int main()
{
    string str = "8923";
    cout << largestOddNumber(str);
    return 0;
}