#include <bits/stdc++.h>
using namespace std;

void pattern0(){
    int n = 5;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern1(){
    int n = 5;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern2(){
    int n = 5;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern3(){
    int n = 5;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << i << " ";
        }
        cout << endl;
    }
}

void pattern4(){
    int n = 5;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
}

int main()
{   
    pattern4();
    return 0;
}