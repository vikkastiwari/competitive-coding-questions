#include <bits/stdc++.h>
using namespace std;

string trimSpaces(const std::string &str) {
    std::string result = str;
    
    // Remove leading spaces
    size_t start = result.find_first_not_of(" \t\n\r");
    if (start != std::string::npos) {
        result = result.substr(start);
    } else {
        result.clear(); // The string only contains spaces
        return result;
    }
    
    // Remove trailing spaces
    size_t end = result.find_last_not_of(" \t\n\r");
    if (end != std::string::npos) {
        result = result.substr(0, end + 1);
    }
    
    return result;
}

string reverseWords(string s) {
    s = trimSpaces(s);
    string res = "";
    string word = " ";
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]!=' '){
            word+=s[i];
        }else if(s[i]==' ' && word!=" "){
            reverse(word.begin(),word.end());
            res+=word;
            if(i!=0) word = " ";
        }
    }
    reverse(word.begin(),word.end());
    res+=word;
    res = trimSpaces(res);
    return res;
}

int main(){
    string s = "  hello world  ";
    string res = reverseWords(s);
    cout << res << endl;
    return 0;
}