#include <bits/stdc++.h>
using namespace std;

/**
 * Using Hashing - Better Solution
 * Time Complexity: O(N)
 * Space Complexity: O(N) 
 */
void maxCounteOne1(vector<int> nums){
    unordered_map<int, int> freq;
    int res = -1;
    for(int i=0;i<nums.size();i++){
        freq[nums[i]]++;
    }
    for(auto itr : freq){
        if(itr.second == 1) res = itr.first;
    }
    cout << res;
}

/**
 * Using XOR - Optimal Solution
 * Time Complexity: O(N)
 * Space Complexity: O(1) 
 */
void maxCounteOne2(vector<int> nums){
    int res = 0;
    for(int i=0;i<nums.size();i++){
        res ^= nums[i];
    }
    cout << res;
}

int main(){
    vector<int> nums;
    nums = { 4,1,2,1,2 }; // op: 4
    maxCounteOne2(nums);
    cout << endl;
    return 0;
}