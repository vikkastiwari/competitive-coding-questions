#include <bits/stdc++.h>
using namespace std;


int search(vector<int> arr,int n,int num)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==num)
            return i;
    }
    return -1;
}

int main(){
    vector<int> nums;
    nums = { 0,1,0,3,12 };
    int searchNum = 3;
    cout << search(nums, nums.size(),searchNum) << endl;
    return 0;
}