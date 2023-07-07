#include <bits/stdc++.h>
using namespace std;

void alternateNums1(vector<int>& nums) {
    vector<int> pos;
    vector<int> neg;
    for(int i=0; i<nums.size();i++){
        if(nums[i]>=0){
            pos.push_back(nums[i]);
        }else{
            neg.push_back(nums[i]);
        }
    }
    for(int i=0; i<nums.size()/2;i++){
        nums[2*i] = pos[i];
        nums[2*i+1] = neg[i];
    }
    for(int i=0; i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

void alternateNums2(vector<int>& nums) {
    int pos=0; int neg=1;
    vector<int> res(nums.size(),0);
    for(int i=0; i<nums.size();i++){
        if(nums[i]>=0){
            res[pos] = nums[i];
            pos+=2;
        }else{
            res[neg] = nums[i];
            neg+=2;
        }
    }
    for(int i=0; i<res.size();i++){
        cout << res[i] << " ";
    }
}

int main()
{
    vector<int> n = {2,1,-3,-4,-5,5};
    alternateNums2(n);
    return 0;
}