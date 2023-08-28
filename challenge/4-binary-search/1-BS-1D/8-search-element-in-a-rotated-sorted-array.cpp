#include <bits/stdc++.h>
using namespace std;

/**
 * @brief binary search approach
 * TC: O(logn)
 * SC: O(1)
 * 
 * @param arr 
 * @param target 
 * @return * int 
 */
int bs(vector<int> arr, int low, int high, int target){
    int occurance = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid]==target){
            occurance = mid;
            high = mid - 1;
        }else if(arr[mid]>target){
            high = mid-1;
        }else{
            low = mid + 1;
        }
    }
    return occurance;
}

/**
 * @brief count occurance
 * TC: O(2^logn)
 * SC: O(1)
 * 
 * @param arr 
 * @param target 
 * @return * int 
 */
int searchElement(vector<int> arr, int target){
    int breakPoint = 0;
    if(arr[breakPoint] == target) return breakPoint;

    for(int i=1;i<arr.size();i++){
        if(arr[i-1]>arr[i]) breakPoint = i;
    }
    if(breakPoint != -1){
        int part1 = bs(arr, 0, breakPoint-1, target);
        int part2 = bs(arr, breakPoint, arr.size()-1, target);
        return part1 != -1 ? part1 : part2;
    }
    return bs(arr, 0, arr.size()-1, target);
}

int main(){
    vector<int> arr = { 0,1,2,3,4,5,6,7 };
    int target = 7;
    cout << searchElement(arr, target) << endl;
    return 0;
}