#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int currentId, int n){
    
    if(currentId > n-1) return;
    int currentIndex = currentId;
    // it runs until the value=arr[currentIndex] is at its correct position
    // e.g. arr[currentIndex-1] < arr[currentIndex] < arr[currentIndex+1]
    while(currentIndex > 0 && arr[currentIndex-1] > arr[currentIndex]){ // in case of sorted array it never runs - best case
        swap(arr[currentIndex - 1], arr[currentIndex]);
        currentIndex--;
    }
    insertionSort(arr,currentId+1,n);
    
}

int main(){
    int arr[] = { 13,46,24,52,20,9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr,0,n);
    cout << "Insertion Sort: ";
    for(int i=0; i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}

