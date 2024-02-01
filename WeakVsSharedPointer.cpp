#include <iostream>
#include <memory>
using namespace std;
class SimpleObject {
public:
    int value;
weak_ptr<SimpleObject> next;
    SimpleObject(int val) : value(val) {
    cout << "Created object with value: " << value << endl;
    }

    ~SimpleObject() {
cout << "Destroyed object with value: " << value << endl;
    }
};

int main() {
    shared_ptr<SimpleObject> obj1 = make_shared<SimpleObject>(1);
shared_ptr<SimpleObject> obj2 = make_shared<SimpleObject>(2);
    obj1->next = obj2;
    obj2->next = obj1;
    
    return 0;
}
