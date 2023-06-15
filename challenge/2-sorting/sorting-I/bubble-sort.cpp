#include <bits/stdc++.h>
using namespace std;

/*
*   Best TC: O(N)
*   Avg & Worst TC: O(N^2)
*/

void bubbleSort(int arr[], int n){
    
    for(int i=n-1; i>=0; i--){
        int didSwap = 0; // optimised 
        for(int j=0;j<=i-1;j++){ // going upto i-1 since we access j+1 to swap adjacent with current
            if(arr[j]>arr[j+1]) { // if we go upto i and try to access j+1 we will get out of bound error
                swap(arr[j],arr[j+1]);
                didSwap = 1;
            }
        }
        if(didSwap == 0) break;
        cout << "run count: " << i << endl;
    }

    cout << "Bubble Sort: ";
    for(int i=0; i<n;i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = { 1,2,3,4,5,6 };
    bubbleSort(arr,sizeof(arr) / sizeof(arr[0]));
    return 0;
}

