
#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

class StringCalculator {
    static bool hasCustomDelimiter(const std::string& numbers) {
        return numbers.find("//") == 0;
    }

    static char extractDelimiter(const std::string& numbers) {
        return numbers[2];
    }

    static std::string extractNumbers(const std::string& numbers) {
        return numbers.substr(4);
    }

    static std::vector<std::string> tokenize(const std::string& numbers, char delimiter) {
        std::vector<std::string> tokens;
        std::stringstream ss(numbers);
        std::string num, strg;
        while (getline(ss, strg, '\n')) {
            std::stringstream lineStream(strg);
            while (getline(lineStream, num, delimiter)) {
                tokens.push_back(num);
            }
        }
        return tokens;
    }

    static int calculateSum(const std::vector<std::string>& numberTokens) {
        int sum = 0;
        for (const auto& token : numberTokens) {
            int currentNum = std::stoi(token);
            if (currentNum < 0) {
                throw std::runtime_error("Negatives not allowed: " + std::to_string(currentNum));
            }
            if (currentNum <= 1000) {
                sum += currentNum;
            }
        }
        return sum;
    }
public:
    static int add(const std::string& numbers) {
        char delimiter = ',';
        if (hasCustomDelimiter(numbers)) {
            delimiter = extractDelimiter(numbers);
            numbers = extractNumbers(numbers);
        }

        std::vector<std::string> numberTokens = tokenize(numbers, delimiter);

        return calculateSum(numberTokens);
    }  
};
