#include <iostream>

// Base class 1
class Animal {
public:
    void eat() {
        std::cout << "Animal is eating." << std::endl;
    }
};

// Base class 2
class Vehicle {
public:
    void drive() {
        std::cout << "Vehicle is driving." << std::endl;
    }
};

// Derived class inheriting from both Animal and Vehicle
class Dog : public Animal, public Vehicle {
public:
    void bark() {
        std::cout << "Dog is barking." << std::endl;
    }
};

int main() {
    Dog myDog;

    myDog.eat();    // Accessing the eat() function from the Animal base class
    myDog.drive();  // Accessing the drive() function from the Vehicle base class
    myDog.bark();   // Accessing the bark() function from the Dog class

    return 0;
}
