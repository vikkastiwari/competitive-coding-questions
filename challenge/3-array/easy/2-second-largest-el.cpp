#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = { 6,5,4,3,2,1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = INT_MIN, secondMax = INT_MIN;
    int min = INT_MAX, secondMin = INT_MAX;
    for(int i=0; i<n;i++){
        if(arr[i]>max) {
            secondMax = max;
            max = arr[i];
        }else if(arr[i]>secondMax && max!=secondMax){
            secondMax = arr[i];
        }

        if(arr[i]<min) {
            secondMin = min;
            min = arr[i];
        }else if(arr[i]<secondMin && min!=secondMin){
            secondMin = arr[i];
        }
    }
    cout << "secondMax: " << secondMax << endl;
    cout << "secondMin: " << secondMin << endl;
    return 0;
}

