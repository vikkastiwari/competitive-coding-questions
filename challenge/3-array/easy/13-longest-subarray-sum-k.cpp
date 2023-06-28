#include <bits/stdc++.h>
using namespace std;

void longestSubarraySumK(vector<int> nums, int K){
    int maxEl = 0, sum = 0;
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            sum = 0;
            for(int k=i; k<=j; k++){
                sum += nums[k];
            }
            if(sum == K){
                maxEl = max(maxEl,j-i+1);
            }
        }
    }
    
    cout << maxEl;
}

int main(){
    vector<int> nums;
    int K = 10;
    nums = { 2,3,5,1,9,0 }; // op: 3
    longestSubarraySumK(nums, K);
    cout << endl;
    return 0;
}