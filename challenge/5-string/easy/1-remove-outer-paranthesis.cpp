#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
    int openBracket = 0, index = -1;
    string res;
    for(int i=0;i<s.size();i++){
        // if(openBracket==0){
        //     index = i;
        // }
        // if(s[i] == '('){
        //     if(i!=index) res += '(';
        //     openBracket++;

        // }else if(s[i] == ')'){
        //     openBracket--;
        //     if(openBracket!=0){
        //         res += ')';
        //     }
        // }

        // second approch

        if(s[i]=='(' && openBracket++>0) res+=s[i];
        if(s[i]==')' && openBracket-->1) res+=s[i];
    }
    return res;
}


int main(){
    string s = "(()()())((()))";
    string res = removeOuterParentheses(s);
    cout << res << endl;
    return 0;
}