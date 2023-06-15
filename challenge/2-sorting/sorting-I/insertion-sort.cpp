#include <bits/stdc++.h>
using namespace std;

/*
*   Best TC: O(N)
*   Avg & Worst TC: O(N^2)
*/
void insertionSort(int arr[], int n){
    
    for(int i=0; i<n; i++){
        int currentIndex=i;
        // it runs until the value=arr[currentIndex] is at its correct position
        // e.g. arr[currentIndex-1] < arr[currentIndex] < arr[currentIndex+1]
        while(currentIndex > 0 && arr[currentIndex-1] > arr[currentIndex]){ // in case of sorted array it never runs - best case
            swap(arr[currentIndex - 1], arr[currentIndex]);
            currentIndex--;
        }
    }

    cout << "Insertion Sort: ";
    for(int i=0; i<n;i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = { 13,46,24,52,20,9 };
    insertionSort(arr,sizeof(arr) / sizeof(arr[0]));
    return 0;
}

