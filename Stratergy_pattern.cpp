#include <iostream>
#include <vector>
#include <functional>
using namespace std;
class Criteria {
public:
    virtual bool meetsCriteria(const string& str) const = 0;
};
class DivisibleByCriteria : public Criteria {
private:
    int divisor;
public:
    DivisibleByCriteria() {}
    bool meetsCriteria(const string& str) const override {
        return str.length() % divisor == 0;
    }
    void setDivisor(int divArg)
    {
        divisor=divArg;
    }
};

class StringFilter {
private:
    const Criteria* criteria;
public:
     StringFilter(const Criteria* criteria) : criteria(criteria) {}

    vector<string> filterStrings(const vector<string>& strings) const {
        vector<string> result;
        for (const string& str : strings) {
            if (criteria->meetsCriteria(str)) {
                result.push_back(str);
            }
        }
        return result;
    }
};
void printStrings(const vector<string>& strings, const string& message) {
    cout << message;
    for (const string& str : strings) {
        cout << str << " ";
    }
    cout << endl;
}
int main() {
    std::vector<std::string> inputStrings = {"apple", "banana", "orange", "grape", "kiwi"};
    DivisibleByCriteria divisibleBy3;
    divisibleBy3.setDivisor(3);
    StringFilter filter(&divisibleBy3);
    vector<string> divisibleStrings = filter.filterStrings(inputStrings);
    printStrings(divisibleStrings, "Strings with length divisible by divisor: ");

    return 0;
}
