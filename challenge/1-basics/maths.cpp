#include <bits/stdc++.h>
using namespace std;

int count(int n){
    int count;
    while(n>0){
        n=n/10;
        count++;
    }
    return count;
}

int reverse(int n){
    int rev = 0;
    while(n>0){
        rev = rev*10 + n%10;
        n=n/10;
    }
    return rev;
}

bool isPalindrome(int n){
    int rev = reverse(n);
    if(rev == n) return true;
    return false; 
}

/*
    GCD or HCF
    The Euclidean algorithm is based on the principle that 
    the greatest common divisor of two numbers does not change 
    if the larger number is replaced by its difference with the smaller number. 
    For example, 21 is the GCD of 252 and 105 (as 252 = 21 × 12 and 105 = 21 × 5), 
    and the same number 21 is also the GCD of 105 and 252 − 105 = 147. 
    Since this replacement reduces the larger of the two numbers, 
    repeating this process gives successively smaller pairs of numbers 
    until the two numbers become equal. 
    When that occurs, they are the GCD of the original two numbers.
*/
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

bool isArmstrong(int n){
    int rev = 0;
    int og = n;
    while(n>0){
        int digit = n%10;
        rev += digit*digit*digit;
        n=n/10;
    }
    if(rev == og) return true;
    return false;
}

bool isPrime(int n){ 
    if(n == 1) return false;
    for(int i=2;i<sqrt(n);i++){
        if(n%i == 0) return false;
    }
    return true;
}

int main()
{   
    cout << isPrime(18) << endl;
    return 0;
}