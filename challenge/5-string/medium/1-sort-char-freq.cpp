#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

/**
 * @brief Sort by freq
 * 
 * @param s 
 * @return * string 
 */
string frequencySort(string s) {
    unordered_map<char, int> maps;
    priority_queue<pair<int,char>> maxheap; 

    for(int i=0;i<s.length();i++){
        maps[s[i]]++;
    }

    // maxheap is constructed wrt frequency
    for(auto it: maps)  maxheap.push({it.second,it.first});
    
    string res="";   
    while(!maxheap.empty()){
        // frequency times the character
        res+=string(maxheap.top().first,maxheap.top().second); 
        maxheap.pop();
    }

    return res;
}

int main(){
    string s = "tree";
    string res = frequencySort(s);
    cout << res << endl; 
    return 0;
}