#include <iostream>

class GCDCalculator {
public:
    // Member function to calculate the GCD using Euclidean algorithm
    int calculateGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main() {
    GCDCalculator gcdCalc; // Create an instance of the GCDCalculator class

    int num1 = 24;
    int num2 = 36;

    int gcd_result = gcdCalc.calculateGCD(num1, num2);

    std::cout << "The GCD of " << num1 << " and " << num2 << " is: " << gcd_result << std::endl;

    return 0;
}