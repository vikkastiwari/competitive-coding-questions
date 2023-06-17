#include <bits/stdc++.h>
using namespace std;

/*
* this will give us two hypothetical array 
* left side array will have elements less than pivot
* right side array will have elements greater than pivot
*/ 
int partitionIdx(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low, j = high;
    while(i<j){
        // this will give us greater element then pivot on left side of pivot
        while(arr[i]<=pivot && i<high) i++;

        // this will give us smaller or equal element then pivot on right side of pivot
        while(arr[j]>pivot && j>low) j--;

        // swap both the elements
        if(i<j) swap(arr[i],arr[j]);

    }
    // j will point to the last element in the left array
    // swapping it will place the pivot to its correct position
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pivotIndex = partitionIdx(arr, low, high);
        quickSort(arr, low, pivotIndex-1);
        quickSort(arr, pivotIndex+1, high);
    }
}

int main(){
    int arr[] = { 6,5,4,3,2,1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr,0,n-1);   
    cout << "Recurssive Quick Sort: ";
    for(int i=0; i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}

