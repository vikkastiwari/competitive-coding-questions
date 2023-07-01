#include <bits/stdc++.h>
using namespace std;

void twoSum1(vector<int> nums, int target){
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j] == target){
                cout << "i: " << i << " " << "j: " << j << endl;
                cout << "num1: " << nums[i] << " " << "num2: " << nums[j] << endl;
                return;
            }
        }
    }
}

/**
 * TC: O(N), where N = size of the array.
 * @reason: The loop runs N times in the worst case and searching in a hashmap takes O(1) generally. 
 *          So the time complexity is O(N).
 * @note: In the worst case(which rarely happens), the unordered_map takes O(N) to find an element. 
 *        In that case, the time complexity will be O(N2). If we use map instead of unordered_map, 
 *        the time complexity will be O(N* logN) as the map data structure takes logN time to find an element.
 * SC: O(N) as we use the map data structure.
 * 
 * @param nums 
 * @param target 
 * @return * void 
 */
void twoSum2(vector<int> nums, int target){
    unordered_map<int,int> hash;
    for(int i=0;i<nums.size();i++){
        int diff = target - nums[i];
        if(hash.find(diff) != hash.end()){
            cout << i << " " << hash[diff] << endl;
            return;
        }else{
            hash[nums[i]] = i;
        }
    }
    cout << "Not Found" << endl; 
}

/**
 * TC: O(N) + O(N*logN)
 * @reason: The loop will run at most N times and sorting array take N*logN time complexity.
 * SC: O(1) 
 * 
 * @note order is not retained to return index of elements wrt original array 
 * 
 * @param nums 
 * @param target 
 * @return * void 
 */
void twoSum3(vector<int> nums, int target){
    int start = 0, end = nums.size()-1;
    sort(nums.begin(), nums.end());
    while(start<end){
        int sum = nums[start] + nums[end];
        if(sum == target){
            cout << "Found" << endl;
            return;
        }else if(sum < target){
            start++;
        }else{
            end--;
        }
    }
    cout << "Not Found" << endl; 
}

int main(){
    vector<int> arr = { 2,6,5,8,11 };
    int target = 14;
    twoSum3(arr,target);
    return 0;
}