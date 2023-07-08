#include <bits/stdc++.h>
using namespace std;

void inbuiltLexiSort(vector<int>& nums) {
    next_permutation(nums.begin(),nums.end());
    for(int i=0; i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> n = {1,3,2};
    inbuiltLexiSort(n);
    return 0;
}