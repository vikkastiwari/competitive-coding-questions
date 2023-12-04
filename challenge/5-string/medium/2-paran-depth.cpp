#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

/**
 * @brief Maximum Nesting Depth of the Parentheses
 * 
 * @param s 
 * @return * int 
 */
int maxDepth(string s) {
    int count = 0, res = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            count++;
        }else if(s[i]==')'){
            count--;
        }
        res = max(res,count);
    }
    return res;
}

int main(){
    string s = "(1+(2*3)+((8)/4))+1";
    int res = maxDepth(s);
    cout << res << endl; 
    return 0;
}