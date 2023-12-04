#include <bits/stdc++.h>
using namespace std;

/**
      1
     212
    32123
   4321234
  543212345
 65432123456
7654321234567

*/
void printPattern(int n){
    for(int i=n-1; i>=0;i--){
        for(int j=0;j<i;j++){
            cout << " ";
        }
        for(int j=n-i;j>0;j--){
            cout << j;
        }
        for(int j=1;j<=n-i-1;j++){
            cout << j+1;
        }
        cout << endl;
    }
}

void printPattern2(int n){
    for(int i=n-1; i>=0;i--){
        for(int j=0;j<i;j++){
            cout << " ";
        }
        for(int j=0;j<n-i;j++){
            cout << j+1;
        }
        for(int j=n-i-1;j>0;j--){
            cout << j;
        }
        cout << endl;
    }
}

int powerNum(int n, int k){
    if(n==0) return 0;
    if(k==0) return 1;
    
    int halfHolder = powerNum(n,k/2);
    int tempRes = halfHolder*halfHolder;
    return k%2==0 ? tempRes : n*tempRes;
}

int removeOdd(vector<int> &arr){
    int i=0,j=1;
    int n = arr.size();
    while(i<n && j<n){
        if(arr[i]%2!=0 && arr[j]%2==0){
            swap(arr[i],arr[j]);
            i++;j++;
        }else if(arr[i]%2==0 && arr[j]%2!=0){
            i++;
        }else if(arr[i]%2!=0 && arr[j]%2!=0){
            j++;
        }else if(arr[i]%2==0 && arr[j]%2==0){
            i++;j++;
        }
    }
    return i;
}

void pushZerosToEnd(vector<int> &arr, int n) {
	    // code here
	
	    int start = 0;
	    int end = 1;
	    while(end<n){
	        if(arr[start] == 0 && arr[end] != 0){
	            swap(arr[start],arr[end]);
	            start++;
	            end++;
	        }
	        while(arr[start] != 0) start++;
	        while(arr[end]==0) end++;
	    }
}

#include <iostream>
#include <string>

std::string removeConsecutiveCharacters(const std::string& input, int consecutiveLength) {
    if (consecutiveLength <= 1) {
        return input; // Nothing to remove if consecutive length is less than or equal to 1.
    }

    std::string result;
    int count = 1;
    char prev = input[0];

    for (size_t i = 1; i < input.size(); ++i) {
        if (input[i] == prev) {
            count++;
        } else {
            if (count != consecutiveLength) {
                result += std::string(count, prev);
            }
            count = 1;
            prev = input[i];
        }
    }

    // Check for the last character group
    if (count != consecutiveLength) {
        result += std::string(count, prev);
    }

    return result;
}

int main() {
    std::string input;
    int consecutiveLength;

    std::cout << "Enter a string: ";
    std::cin >> input;

    std::cout << "Enter the consecutive length to remove: ";
    std::cin >> consecutiveLength;

    std::string result = removeConsecutiveCharacters(input, consecutiveLength);
    std::cout << "Result: " << result << std::endl;

    return 0;
}


int main()
{
    int n = 2;
    int k = 5;
    // vector<int> arr = {4,1,2,2,5,8,1,0,3,9,6};
    // vector<int> arr = {4,2,2,8,1};
    // cout << powerNum(n,k) << endl;
    vector<int> ar = {1,0,3,0,0,4,0,0,2,4,0,53,0,2,42};
    pushZerosToEnd(ar,ar.size());
    // int oddCount = arr.size() - removeOdd(arr);
    for(int i=0;i<ar.size();i++){
        cout << ar[i] << " ";
    }
    cout << endl;
    return 0;
}