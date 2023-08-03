
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Example 1:
 *   Input Format: N = 5, array[] = {1,2,2,3,2}
 *   Result: 2
 *   Explanation: Here we can see that the Count(1) = 1, Count(2) = 3 and Count(3) = 1.Therefore, the count of 2 is greater than N/3 times. Hence, 2 is the answer.
 */

/**
 * TC: O(nlogn)
 * SC: O(n)
 * We are also using a list that stores a maximum of 2 elements. 
 * That space used is so small that it can be considered constant.
 * 
 * @param arr 
 * @return * vector<int> 
 */

vector<int> majorityElementBetter(vector<int> arr){
    map<int, int> map;
    vector<int> res;
    for(int i=0;i<arr.size();i++){
        map[arr[i]]++;
    }
    for(auto itr : map){
        if(itr.second > arr.size()/3){
            res.push_back(itr.first);
        }
    }
    return res;
}

vector<int> majorityElementOptimal(vector<int> arr){
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;
    
    vector<int> res;
    for(int i=0;i<arr.size();i++){
        if(cnt1=0 && el2!=arr[i]){  
            cnt1++;
            el1 = arr[i];
        }else if(cnt2=0 && el1!=arr[i]){
            cnt2++;
            el2 = arr[i];
        }else if(arr[i] == el1){
            cnt1++;
        }else if(arr[i] == el2){
            cnt2;
        }else {
            cnt1--; cnt2--;
        }
    }
    if(cnt1 > arr.size()/3){
        res.push_back(el1);
    }
    if(cnt2 > arr.size()/3){
        res.push_back(el2);
    }
    return res;
}


int main()
{
    vector<int> arr = {11,33,33,11,33,11};
    vector<int> res = majorityElementBetter(arr);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
