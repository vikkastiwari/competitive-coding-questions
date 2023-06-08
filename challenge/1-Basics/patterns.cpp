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

void pattern5(){
    int n = 5;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout << " ";
        }
        for(int j=0;j<2*i+1;j++){
            cout << "*";
        }
        cout << endl;
    }
}

void pattern6(){
    int n = 5;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n-i-1;j++){
            cout << " ";
        }
        for(int j=0;j<2*i+1;j++){
            cout << "*";
        }
        cout << endl;
    }
}

void pattern7(){
    int n = 5;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout << " ";
        }
        for(int j=0;j<2*i+1;j++){
            cout << "*";
        }
        cout << endl;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n-i-1;j++){
            cout << " ";
        }
        for(int j=0;j<2*i+1;j++){
            cout << "*";
        }
        cout << endl;
    }
}

void pattern8(){
    int n = 5;
    for(int i=1;i<=2*n-1;i++){ // 2 iteration where one line is subracted
        int star = i;
        if(i>n) star = 2*n - i; // second part of the pattern
        for(int j=1;j<=star;j++){
            cout << "*";
        }
        cout << endl;
    }
    // also we can achieve this by using two for loops and printing patterns in half
}

void pattern9(){
    int n = 5;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(i%2 == 0){ // 3%2 == 1 , 2%2 == 0
                cout << (j%2 == 0 ? 1 : 0 );
            }else{
                cout << (j%2 == 0 ? 0 : 1 );
            }
        }
        cout << endl;
    }
}

/*

1      1
12    21
123  321
12344321

*/ 
void pattern10(){
    int n = 5;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << j;
        }
        for(int j=1;j<=2*(n-1);j++){
            // wrong output
            cout << " "; 
        }
        for(int j=i;j>=1;j--){
            cout<<j;
        }
        cout << endl;
    }
}

void pattern11(){
    int n = 5;
    int val = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << val++ << " ";
        }
        cout << endl;
    }
}

void pattern12(){
    int n = 5;
    for(int i=1;i<=n;i++){
        char val = 'A';
        for(int j=1;j<=i;j++){
            cout << val++ << " ";
        }
        cout << endl;
    }
}

void pattern13(){
    int n = 5;
    for(int i=n;i>=1;i--){
        char val = 'A';
        for(int j=1;j<=i;j++){
            cout << val++ << " ";
        }
        cout << endl;
    }
}

void pattern14(){
    int n = 5;
    for(int i=n;i>=1;i--){
        char val = 'A';
        for(int j=1;j<=i;j++){
            cout << val++ << " ";
        }
        cout << endl;
    }
}

void pattern15(){
    int n = 5;
    char val = 'A';
    for(int i=0;i<n;i++){
        for(int j=n-i-1;j<=n-1;j++){
            cout << char(65+j);
        }
        cout << endl;
    }
}

void pattern16(){
    int n = 5;
    for(int i=0;i<n;i++){
        char val = 'A';
        for(int j=0;j<n-i-1;j++){
            cout << " ";
        }
        for(int j=1;j<=2*i+1;j++){
            cout << val;
            if(j<=(2*i+1)/2) val++;
            else val--;
        }
        cout << endl;
    }
}

void pattern17(){
    int n = 5;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout << "*";
        }
        for(int j=1;j<2*i+1;j++){
            cout << " ";
        }
        for(int j=n-i-1;j>=0;j--){
            cout << "*";
        }
        cout << endl;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n-i;j++){
            cout << "*";
        }
        for(int j=1;j<2*i+1;j++){
            cout << " ";
        }
        for(int j=n-i-1;j>=0;j--){
            cout << "*";
        }
        cout << endl;
    }
}

void pattern18(){
    int n = 5;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=n-i-1;j++){
            cout << "*";
        }
        for(int j=1;j<2*i+1;j++){
            cout << " ";
        }
        for(int j=0;j<=n-i-1;j++){
            cout << "*";
        }
        cout << endl;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=n-i-1;j++){
            cout << "*";
        }
        for(int j=1;j<2*i+1;j++){
            cout << " ";
        }
        for(int j=0;j<=n-i-1;j++){
            cout << "*";
        }
        cout << endl;
    }
}

int main()
{   
    pattern18();
    return 0;
}