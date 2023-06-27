#include <bits/stdc++.h>
using namespace std;

void maxConsecutiveOnes(vector<int> nums){
    int max = 0;
    int counter = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] == 1){
            counter++;
            if(counter>max) max = counter;
        }else{
            counter = 0;
        }
    }
    cout << max;
}

int main(){
    vector<int> nums;
    nums = { 1, 1, 0, 1, 1, 1 }; // op: 3
    maxConsecutiveOnes(nums);
    cout << endl;
    return 0;
}