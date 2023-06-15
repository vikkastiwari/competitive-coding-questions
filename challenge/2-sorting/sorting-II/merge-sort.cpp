#include <bits/stdc++.h>
using namespace std;

/*
*   Best TC: O(N)
*   Avg & Worst TC: O(N^2)
*/
void merge(int arr[], int low, int mid, int high){
    int left=low;
    int right = mid+1;
    vector<int> temp;

    while(left <= mid && right <= high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
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

    for(int i=low; i<=high;i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(int arr[], int low, int high){
    
    if(low>=high) return;
    int mid = (low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main(){
    int arr[] = { 13,46,24,52,20,9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}

