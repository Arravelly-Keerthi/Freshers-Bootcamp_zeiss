#pragma once
#include <string>
#include <sstream>

using namespace std;

int add(string numbers) {
    // Default delimiter is ','
    char delimiter = ',';

    // Check if a custom delimiter is specified
    if (numbers.find("//") == 0) {
        delimiter = numbers[2];
        // Update numbers to exclude the delimiter specification
        numbers = numbers.substr(4);
    }

    int sum = 0;
    // Create a stringstream from the input string
    stringstream ss(numbers);
    string num, strg;

    // Iterate through each line in the input string
    while (getline(ss, strg, '\n')) {
        // Create a stringstream for the current line
        stringstream lineStream(strg);

        // Iterate through each number in the line using the specified delimiter
        while (getline(lineStream, num, delimiter)) {
            int currentNum = stoi(num);

            // Check if the current number is negative, and throw an exception if it is
            if (currentNum < 0) {
                throw runtime_error("negatives not allowed: " + to_string(currentNum));
            }

            // Add the current number to the sum if it is less than or equal to 1000
            if (currentNum <= 1000) {
                sum += currentNum;
            }
        }
    }

    // Return the sum of valid numbers
    return sum;
}