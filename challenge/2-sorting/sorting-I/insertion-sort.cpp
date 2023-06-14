#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    
    cout << "Insertion Sort: ";
    for(int i=0; i<n; i++){
        int currentIndex=i;
        // it runs until the value=arr[currentIndex] is at its correct position
        // e.g. arr[currentIndex-1] < arr[currentIndex] < arr[currentIndex+1]
        while(currentIndex > 0 && arr[currentIndex-1] > arr[currentIndex]){
            swap(arr[currentIndex - 1], arr[currentIndex]);
            currentIndex--;
        }
    }

    for(int i=0; i<n;i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = { 13,46,24,52,20,9 };
    insertionSort(arr,sizeof(arr) / sizeof(arr[0]));
    return 0;
}

