
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums) {
    int count = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i - 1])
            count++;
    };
    if( nums[0]<nums[nums.size()-1] )
        count++;
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
