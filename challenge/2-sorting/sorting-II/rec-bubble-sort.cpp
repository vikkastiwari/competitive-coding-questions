#include <bits/stdc++.h>
using namespace std;

void recBubbleSort(int arr[], int start, int n){
    if(n==1) return;
    while(arr[start]>arr[start+1]){
        swap(arr[start],arr[start+1]);
        start++;
    }
    recBubbleSort(arr,0,n-1);   
}

int main(){
    int arr[] = { 6,5,4,3,2,1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    recBubbleSort(arr,0,n);
    cout << "Recurssive Bubble Sort: ";
    for(int i=0; i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}

