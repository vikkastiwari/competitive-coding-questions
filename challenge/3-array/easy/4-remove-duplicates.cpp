#include <bits/stdc++.h>
using namespace std;

/** 
 * Take a variable i as 0;
 * Use a for loop by using a variable ‘j’ from 1 to length of the array.
 * If arr[j] != arr[i], increase ‘i’ and update arr[i] == arr[j].
 * After completion of the loop return i+1, i.e size of the array of unique elements.
*/
void removeDups(vector<int>& nums) {
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[i] != nums[j]){
            i++;
            nums[i] = nums[j];
        }
    };
    for(int k = 0; k <= i; k++){
        cout << nums[k] << " ";
    };
    cout << endl;
}

int main(){
    vector<int> nums;
    nums = { 1,1,2,2,2,3,3,4 };
    removeDups(nums);
    return 0;
}
