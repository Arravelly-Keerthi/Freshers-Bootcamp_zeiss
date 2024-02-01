#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

auto isDivisibleBy(const string& str, int divisor) {
    return str.length() % divisor == 0;
}

vector<string> search(vector<string>&& strings, function<bool(const string&)>&& criteria) {
    vector<string> result;
    for (string& str : strings) {
        if (criteria(str)) {
            result.push_back(move(str));
        }
    }
    return result;
}

void printDivisibleStrings(vector<string>&& divisibleStrings) {
    cout << "Strings with length divisible by divisor: ";
    for (const string& str : divisibleStrings) {
        cout << str << " ";
    }
    cout << endl;
}

int main() {
    int divisor = 3;
    auto isDivisibleByDivisor = bind(isDivisibleBy, _1, divisor);
    vector<string> strings = {"apple", "banana", "orange", "grape", "kiwi", "pear", "melon"};
    vector<string> divisibleStrings = search(move(strings), isDivisibleByDivisor);
    printDivisibleStrings(move(divisibleStrings));
    return 0;
}
