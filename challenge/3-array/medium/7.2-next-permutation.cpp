#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 
 * 
 * TC: O(3*N)
 * SC: O(1)
 * 
 * @param nums 
 * @return * void 
 */
void nextPermutation(vector<int>& nums) {
    int index=-1;
    for(int i=nums.size()-2; i>=0; i--){ // select largest possible fixed prefix
        if(nums[i]<nums[i+1]){
            index=i; // find break point where nums[i]<nums[i+1]
            break;
        }
    }        
    /**
     * if break point not means given 
     * input is last permutation, 
     * return first permutation by 
     * reversing the input
     */
    if(index==-1){ 
        reverse(nums.begin(),nums.end());
    }else{
        for(int i=nums.size()-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[index],nums[i]); // swap the i from which break point is found with slightly greater element to get next possible permutation
                break;
            }
        }
        // after swapping reverse all the remaining values from index+1 to get min number 
        // 5 4 1 0 0 --reversed--> 0 0 1 4 5
        reverse(nums.begin()+index+1,nums.end()); 
    }
}

int main(){
    // vector<int> n = {1,3,2};
    vector<int> n = {2,1,5,4,3,0,0};
    nextPermutation(n);
    for(int i=0;i<n.size();i++){
        cout << n[i] << " "; 
    }
    cout << endl;
    return 0;
}