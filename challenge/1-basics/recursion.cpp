#include <bits/stdc++.h>
using namespace std;

void print1ton(int start,int n){
    if(start>n) return;
    cout << start << endl;
    print1ton(start+1,n);
}

void sum(int sumVal,int n){
    cout << sumVal << endl;
    if(n<=0) return;
    sum(sumVal+n,n-1);
}

void factorial(int sumVal,int n){
    cout << sumVal << endl;
    if(n<=0) return;
    factorial(sumVal*n,n-1);
}

void printArray(int arr[], int n) {
   cout << "Reversed array : ";
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

void reverse(int val[], int start, int end){
    // loop method
    // int arr[n];
    // for(int i=n-1;i>=0;i++){
    //     arr[n-i-1] = arr[i];
    // }

    // recursive method
    if(start>=end) return;
    swap(val[start],val[end]);
    reverse(val,start+1,end-1);
}

int fib(int n){
    // recursive call to get the nth fibonacci number 
    if(n<=1) return n;
    return fib(n-1) + fib(n-2);
}

void reverseStr(string s, int start, int end){
    if(start>=end) return;
    swap(s[start],s[end]);
    reverseStr(s,start+1,end-1);
}

void palindrome(string s){
    string rev = s;
    reverseStr(rev,0,rev.length()-1);
    cout << s << endl;
    if(rev == s) cout << "Plaindrome" << endl;
    else cout << "Not Palindrome" << endl;
}

int main(){
    // int arr[] = {1,2,3,4,5};
    // reverse(arr,0,(sizeof(arr) / sizeof(arr[0]))-1);
    // printArray(arr,sizeof(arr) / sizeof(arr[0]));

    int i = 0;
    while(i<6){
        cout << fib(i) << endl;
        i++;
    }

    palindrome("ABCBA");
    return 0;
}