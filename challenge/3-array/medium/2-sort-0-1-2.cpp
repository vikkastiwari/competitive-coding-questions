#include <bits/stdc++.h>
using namespace std;

void customSort1(vector<int> nums)
{
    map<int, int> freq;
    for (int i = 0; i < nums.size(); i++) {
        freq[nums[i]]++;        
    }
    int j = 0;
    for(auto itr:freq){
        int count = itr.second;
        while(count && j<nums.size()){
            nums[j] = itr.first;
            cout << itr.first<< endl;
            count--;j++;
        }
    }
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

void customSort2(vector<int> nums){
    int count_0 = 0, count_1 = 0, count_2 = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0) count_0++;
        else if(nums[i]==1) count_1++;
        else if(nums[i]==2) count_2++;
    }
    for (int i = 0; i < count_0; i++) nums[i] = 0; 
    for (int i = count_0; i < count_0 + count_1; i++) nums[i] = 1;
    for (int i = count_0 + count_1; i < nums.size(); i++) nums[i] = 2;
    
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

/**
 * @brief Dutch National Flag Algo
 * Thought Process: put zeros to extreme left, 2 to extreme right and 1 in between of 0 and 2
 * 
 * TC: O(N)
 * SC: O(1)
 * 
 * @param nums 
 * @return * void 
 */

/**
 * @note Diagram to visualise
 * 
 * pointer     0      low-1   low      mid-1  mid    high   high+1     n-1
 * array       0   0    0      1   1     1     unsorted        2    2   2
 *          
 */
void customSort3(vector<int> nums){
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;
    while(low < n && mid <= high && high >= 0){
        if(nums[mid] == 0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        } else if(nums[mid]==1) {
            mid++;
        }else if(nums[mid]==2){
            swap(nums[mid],nums[high]);
            high--;
        }
    }
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    customSort3(arr);
    return 0;
}