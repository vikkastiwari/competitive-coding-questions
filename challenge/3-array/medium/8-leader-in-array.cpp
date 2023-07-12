#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 
 * 
 * TC: O(N*N)
 * SC: O(N)
 * 
 * @param nums 
 * @return * void 
 */
void leaderInArray1(vector<int>& nums) {
    for(int i=0;i<nums.size();i++){
        int leader = nums[nums.size()-1];
        int count = 0;
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]>nums[j]){
                count++;
                leader = nums[i];
            }else{
                leader = -1;
            }
        }
        if(count == nums.size()-1-i && leader!=-1)
            cout << leader << " ";
    }
    cout << endl;
}

void printLeaders(vector<int> arr) {
    int n = arr.size();
    int max = arr[n - 1];
    cout << arr[n-1] << " ";

    for (int i = n - 2; i >= 0; i--){
        if (arr[i] > max) {
        cout << arr[i] << " ";
        max = arr[i];
        }
    }
}

int main(){
    // vector<int> n = {1,3,2};
    vector<int> n = {10, 22, 12, 3, 0, 6};
    leaderInArray1(n);
    return 0;
}