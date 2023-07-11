#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 
 * 
 * TC: O(N*N)
 * SC: O(N)
 * 
 * @param nums 
 * @return * void 
 */
void leaderInArray1(vector<int>& nums) {
    for(int i=0;i<nums.size();i++){
        int leader = nums[nums.size()-1];
        int count = 0;
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]>nums[j]){
                count++;
                leader = nums[i];
            }else{
                leader = -1;
            }
        }
        if(count == nums.size()-1-i && leader!=-1)
            cout << leader << " ";
    }
    cout << endl;
}

int main(){
    // vector<int> n = {1,3,2};
    vector<int> n = {10, 22, 12, 3, 0, 6};
    leaderInArray1(n);
    // for(int i=0;i<n.size();i++){
    //     cout << n[i] << " "; 
    // }
    // cout << endl;
    return 0;
}