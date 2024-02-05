#include <iostream>
#include <fstream>
#include <string>
#include "./add.h"

using namespace std;

int main() {
    cout << "Choose an option:" << endl;
    cout << "1. Enter the string manually" << endl;
    cout << "2. Load the string from the input.txt file" << endl;
    int choice;
    cin >> choice;
    string inputString;

    // Handle user choice
    if (choice == 1) {
        // Manually enter the string
        cout << "Enter the string: ";
        cin >> inputString;
    }
    else if (choice == 2) {
        // Load the string from the input.txt file
        ifstream inputFile("input.txt");
        // Check if the file is open
        if (!inputFile.is_open()) {
            cerr << "Error opening the input.txt file." << endl;
            return 1;
        }

        // Read the string from the file
        getline(inputFile, inputString);
    }
    else {
        // Invalid choice, exit with an error message
        cerr << "Invalid choice. Exiting." << endl;
        return 1;
    }

    try {
        // Call the add function and display the result
        cout << "Result: " << add(inputString) << endl;
    }
    catch (const exception& e) {
        // Handle exceptions and display error message
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}