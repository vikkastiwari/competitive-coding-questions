#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Backtracking - problems that ask you to find all of something with low bounds can be solved with backtracking.
 * 
 * TC: O(N*N!)
 * SC: O(N)
 * 
 * @param nums 
 * @param ans 
 * @param index 
 * @return * void 
 */
void solve(vector<int> nums,vector<vector<int>>& ans, int index){
    if(index>=nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=index;i<nums.size();i++){
        swap(nums[i],nums[index]);
        solve(nums,ans,index+1);
        // backtrack - undo swap
        swap(nums[i],nums[index]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    solve(nums,ans,0);
    return ans;
}

int main(){
    vector<int> n = {1,3,2};
    vector<vector<int>> ans =  permute(n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " "; 
        }
        cout << endl;
    }
    return 0;
}