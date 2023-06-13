#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    
    cout << "Bubble Sort: ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = { 13,46,24,52,20,9 };
    bubbleSort(arr,sizeof(arr) / sizeof(arr[0]));
    return 0;
}

