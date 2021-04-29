// Reference - https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

/*
There two more approaches 
1) Tournamnet Method
2) Compare in Pairs

Both with Time Complexity : O(n)
*/

#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(n)
void takeInput(int arr[],int n){
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
}

struct Pair{
    int min;
    int max;
};

struct Pair arrayMinMax(int arr[], int n){
    struct Pair minmax;
    int i;
    if(n==1){
        minmax.min=arr[0];
        minmax.max=arr[0];
        return minmax;
    }
    if(arr[0]>arr[1]){
        minmax.max=arr[0];
        minmax.min=arr[1];
    }else{
        minmax.min=arr[0];
        minmax.max=arr[1];
    }
    for(int i=2;i<n;i++){
        if(arr[i]>minmax.max){
            minmax.max=arr[i];
        }else if(arr[i]<minmax.min){
            minmax.min=arr[i];
        }
    }
    return minmax;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    takeInput(arr,n);
    struct Pair minmax = arrayMinMax(arr,n);
    cout << "Min: " << minmax.min << endl;
    cout << "Max: " << minmax.max << endl;
    return 0;
}