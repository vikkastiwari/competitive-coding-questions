#include <bits/stdc++.h>
using namespace std;

/**
 * TC: O(N)
 * SC: O(1)
 * 
 * @param nums 
 * @return * int 
 */
int buySellStocks(vector<int>& nums) {
    int min = INT_MAX, max = 0, profit=0;
    for(int i=0; i<nums.size();i++){
        min = std::min(nums[i],min);
        profit = std::max(profit,nums[i]-min);
    }
    return profit;
}


int main()
{
    vector<int> n = {7,1,5,3,6,4};
    cout << buySellStocks(n) << endl;
    return 0;
}