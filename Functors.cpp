#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class IsDivisibleBy {
    int divisor;
public:
    IsDivisibleBy() {}

    bool operator()(const string& str) const {
        return str.length() % divisor == 0;
    }

    void setDivisor(int divArg) {
        divisor = divArg;
    }
};

vector<string> search(const vector<string>& strings, function<bool(const string&)> criteria) {
    vector<string> result;
    for (const string& str : strings) {
        if (criteria(str)) {
            result.push_back(str);
        }
    }
    return result;
}

void printDivisibleStrings(const vector<string>& divisibleStrings) {
    cout << "Strings with length divisible by divisor: ";
    for (const string& str : divisibleStrings) {
        cout << str << " ";
    }
    cout << endl;
}

int main() {

    IsDivisibleBy isDivisibleFunctor;
    isDivisibleFunctor.setDivisor(3);
    function<bool(const string&)> isDivisibleByDivisor(isDivisibleFunctor);

    vector<string> strings = {"apple", "banana", "orange", "grape", "kiwi", "pear", "melon"};
    vector<string> divisibleStrings = search(strings, isDivisibleByDivisor);
    printDivisibleStrings(divisibleStrings);

    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------------------------
    
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class IsDivisibleBy {
    int divisor;
public:
    IsDivisibleBy(){}

    bool operator()( string&& str) const {
        return str.length() % divisor == 0;
    }
    void setDivisor(int divArg)
    {
        divisor=divArg;
    }
};

class Search {
    function<bool( string&&)>  criteria;
public:
    Search() {}
 void setCriteria(function<bool( string&&)> critArg)
 {
     criteria=critArg;
 }
    vector<string> operator()(vector<string>&& strings) const {
        vector<string> result;
        for (string& str : strings) {
            if (criteria(move(str))) {
                result.push_back(move(str));
            }
        }
        return result;
    }
    
};

void printDivisibleStrings(vector<string>&& divisibleStrings) {
    cout << "Strings with length divisible by divisor: ";
    for ( const string& str: divisibleStrings) {
        cout << str << " ";
    }
    cout << endl;
}

int main() {
  
    IsDivisibleBy isDivisibleFunctor;
    isDivisibleFunctor.setDivisor(3);
   function<bool(string&&)> isDivisibleByDivisor(isDivisibleFunctor);

    Search searchFunctor;
    searchFunctor.setCriteria(isDivisibleByDivisor);
    vector<string> strings = {"apple", "banana", "orange", "grape", "kiwi", "pear", "melon"};
    vector<string> divisibleStrings = searchFunctor(move(strings));
    printDivisibleStrings(move(divisibleStrings));

    return 0;
}

