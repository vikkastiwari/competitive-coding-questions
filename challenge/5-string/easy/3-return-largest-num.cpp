#include <bits/stdc++.h>
using namespace std;

/**
 * @brief logic using stoi function but its giving some out of range error in env
 * 
 * @param num 
 * @return * string 
 */
string largestOddNumber(string num) {
    long long n = stoi(num);
    if(n%2!=0) return num;

    long long res = 0, temp = n;
    long long val;
    for(int i=0;i<num.length();i++){
        val = temp%10;
        
        if(val%2!=0) res = max(res,val);
        temp = temp / 10;

        if(temp%2!=0) res = max(res,temp);
    }
    return res!=0 ? to_string(res) : "";
}

/**
 * @brief largest odd number
 * TC: O(n)
 * SC: O(1)
 * 
 * @param num 
 * @return * string 
 */
string largestOddNumber(string num) {
    int n = num.size();
    for(int i=n-1; i>=0; i--){
        // we are checking from back, for largest odd num
        if((num[i]-'0')%2 !=0) return num.substr(0, i+1);
    }
    return "";
}

int main(){
    string s = "35427";
    string res = largestOddNumber(s);
    cout << res << endl;
    return 0;
}