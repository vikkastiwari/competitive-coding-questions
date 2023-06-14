#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    
    cout << "Bubble Sort: ";
    for(int i=n-1; i>=0; i--){
        for(int j=0;j<=i-1;j++){ // going upto i-1 since we access j+1 to swap adjacent with current
            if(arr[j]>arr[j+1]) // if we go upto i and try to access j+1 we will get out of bound error
                swap(arr[j],arr[j+1]);
        }
    }

    for(int i=0; i<n;i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = { 13,46,24,52,20,9 };
    bubbleSort(arr,sizeof(arr) / sizeof(arr[0]));
    return 0;
}

