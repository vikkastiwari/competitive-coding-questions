#include <bits/stdc++.h>
using namespace std;

/**
 * TC: O(N*2)
 * SC: O(1)
 * 
 * @param nums 
 * @return * int 
 */
int maxSubArrayProd(vector<int>& nums) {
    int maxProd = nums[0];
    for(int i=0;i<nums.size();i++){
        int term = nums[i];
        for(int j=i+1;j<nums.size();j++){
            maxProd = max(maxProd,term);
            term = term*nums[j];
        }
        maxProd = max(maxProd,term);
    }
    return maxProd;
}

/**
 * @brief Intutive based algorithm
 * TC: O(N)
 * SC: O(1)
 * 
 * @param nums 
 * @return * int 
 */
int maxSubArrayProd2(vector<int>& nums) {
    int pre = 1, suff = 1;
    int maxProd = INT_MIN;
    for(int i=0;i<nums.size();i++){
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;
        pre *= nums[i];
        suff *= nums[nums.size()-1-i];
        maxProd = max(maxProd,max(pre,suff));
    }
    return maxProd;
}

int main()
{
    vector<int> n = {1,2,-3,0,-4,-5};
    cout << maxSubArrayProd2(n) << endl;
    return 0;
}