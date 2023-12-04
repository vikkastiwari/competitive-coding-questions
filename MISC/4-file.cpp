#include <iostream>
#include <fstream> // File handling library
using namespace std;

int main() {
    // Writing to a file
    std::ofstream outFile("example.txt"); // Create an output file stream
    std::cout << "example.txt file created" << std::endl;

    if (outFile.is_open()) {
        std::cout << "Writing...." << std::endl;
        outFile << "Hello, World!" << std::endl;
        outFile << "This is a C++ file handling example." << std::endl;
        outFile.close(); // Close the file
        std::cout << "Data has been written to the file." << std::endl;
    } else {
        std::cerr << "Failed to open the file for writing." << std::endl;
    }

    // Reading from a file
    std::ifstream inFile("example.txt"); // Create an input file stream
    std::cout << "---------- Data Written in file ----------" << std::endl;

    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close(); // Close the file
    } else {
        std::cerr << "Failed to open the file for reading." << std::endl;
    }

    return 0;
}
