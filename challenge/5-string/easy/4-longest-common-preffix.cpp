#include <bits/stdc++.h>
using namespace std;

/**
 * @brief longestCommonPrefix
 * 
 * @param strs 
 * @return * string 
 */
string longestCommonPrefix(vector<string>& strs) {
    // sorts vector wrt dictionary
    sort(strs.begin(),strs.end());
    
    int a=strs.size();
    // first and last words will have most differences in them
    string n=strs[0],m=strs[a-1],res="";

    // so we iterate and compare them to find largest common preffix
    for(int i=0;i<n.size();i++){
        if(n[i]==m[i])
            res+=n[i];
        else 
            break;
    }
    return res;
}

int main(){
    vector<string> s = {"flower","flow","flight"};
    string res = longestCommonPrefix(s);
    cout << res << endl;
    return 0;
}