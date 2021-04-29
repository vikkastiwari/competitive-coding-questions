// https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

// Note : provide sorted array to reverse it when you dont use sort function
#include <bits/stdc++.h>
using namespace std;

void reverseArray(string arr[], int start, int end){
    while(start<end){
        string temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void takeInput(string arr[],int n){
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
}

void printOutput(string arr[], int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n;
    cin >> n;
    string arr[n];
    takeInput(arr,n);
    sort(arr,arr+n);
    reverseArray(arr,0,n-1);
    printOutput(arr,n);   
}