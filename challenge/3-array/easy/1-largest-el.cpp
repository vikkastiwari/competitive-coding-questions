#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = { 6,5,4,3,2,1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = -1;
    for(int i=0; i<n;i++){
        if(arr[i]>max) max = arr[i];
    }
    cout << "max: " << max << " ";
    return 0;
}

