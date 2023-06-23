
#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int lastNonZeroFoundAt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            swap(nums[lastNonZeroFoundAt++] ,nums[i]);
        }
    }
}
int main(){
    vector<int> nums;
    // nums = { 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1 };
    nums = { 0,1,0,3,12 };
    moveZeroes(nums);
    for(int i = 0; i<nums.size(); i++){
        cout << nums[i] << " "; 
    }
    cout << endl;
    return 0;
}
