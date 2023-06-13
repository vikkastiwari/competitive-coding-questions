#include <bits/stdc++.h>
using namespace std;

/*
----------Refer for simplicity-----------
void selection_sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int mini = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[mini]) {
        mini = j;
      }
    }
    int temp = arr[mini];
    arr[mini] = arr[i];
    arr[i] = temp;
  }

  cout << "After selection sort: " << "\n";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}
*/ 

int min(int arr[], int start, int n){
    int min = arr[start];
    int currentMinId = -1;
    for(int i=start; i<n; i++){
        if(arr[i] < min) {
            min = arr[i];
            currentMinId = i;
        }
    }
    return currentMinId == -1 ? start : currentMinId;
}

void selectionSort(int arr[], int n){
    int minIndex = 0;
    int start = 0;
    for(int i=0; i<n; i++){
        minIndex = min(arr,i,n);
        swap(arr[start],arr[minIndex]);
        if(start<=n-2) start++;
    }
    cout << "Selection Sort: ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){

    int arr[] = { 13,46,24,52,20,9 };
    selectionSort(arr,sizeof(arr) / sizeof(arr[0]));
    return 0;
}

