#include <bits/stdc++.h>
using namespace std;

void countInversionsBrute(vector<int> arr) {
    int count = 0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[i]) count++;
        }
    }
    cout << count << endl;
}

/**
 * @brief Optimal solution using merge sort approach
 * 
 * @param arr 
 * @param low 
 * @param mid 
 * @param high 
 * @return * int 
 */
int merge(vector<int> &arr, int low, int mid, int high){
    int left=low;
    int right = mid+1;
    int count = 0;
    vector<int> temp;

    while(left <= mid && right <= high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            count += (mid - left + 1);
            right++;
        }
    }
    while(left<=mid){ // case where left array is greater than right
        temp.push_back(arr[left]);
        left++;
    }
     while(right<=high){ // case where right array is greater than left
        temp.push_back(arr[right]);
        right++;
    }
    // transfering all elements from temporary to arr
    for(int i=low; i<=high;i++){
        arr[i] = temp[i-low];
    }

    return count;
}

int mergeSort(vector<int> &arr, int low, int high){
    int count = 0;
    if(low>=high) return count;
    int mid = (low+high)/2;
    count += mergeSort(arr,low,mid);
    count += mergeSort(arr,mid+1,high);
    count += merge(arr,low,mid,high);
    return count;
}

/**
 * @brief Optimal solution using merge sort 
 * TC: O(nlogn)
 * SC: O(n)
 * 
 * @param arr 
 * @return * void 
 */
void countInversionsOptimal(vector<int> &arr) {
    cout << mergeSort(arr,0,arr.size()-1) << endl;
}

int main(){
    vector<int> arr = {5,4,3,2,1};
    countInversionsOptimal(arr);
    return 0;
}
