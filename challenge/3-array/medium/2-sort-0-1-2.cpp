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

int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    customSort2(arr);
    return 0;
}