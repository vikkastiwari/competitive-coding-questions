
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums) {
    int count = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i - 1]) // it counts one left rotation
            count++;
    };
    if( nums[0]<nums[nums.size()-1] ) // it checks for sorted array without rotation
        count++;
    
    // in order to check that array is sorted any one should exist from above two case
    return count > 1 ? false : true;
}

int main(){
    vector<int> nums;
    // nums = { 6,5,4,3,2,1 };
    nums = { 3,4,5,1,2 };
    // nums = { 2,1,3,4 };
    cout << "Is Sorted: " << check(nums) << endl;
    return 0;
}
