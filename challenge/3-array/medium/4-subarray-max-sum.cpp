#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Kadane’s Algorithm : Maximum Subarray Sum in an Array
 * TC: O(N)
 * SC: O(1)
 * 
 * @param nums 
 * @return * int 
 */
int maxSubArray(vector<int>& nums) {
    int max = nums[0], sum=nums[0];
    for(int i=1; i<nums.size();i++){
        sum = std::max(nums[i],sum+nums[i]);
        max = std::max(sum,max);
    }
    return max;
}


int main()
{
    vector<int> n = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(n) << endl;
    return 0;
}