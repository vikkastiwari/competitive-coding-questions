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


int main()
{
    int n = 7;
    printPattern2(n);
    return 0;
}