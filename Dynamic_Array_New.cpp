#include <iostream>
using namespace std;

class A {
    int x;

public:
    void setX(int xArg) {
        x = xArg;
    }
    int getX() const {
        return x;
    }
    ~A() {
        cout << "A's Destructor " << endl;
    }
    friend ostream& operator<<(ostream& out, const A& obj) {
        out << obj.getX();
        return out;
    }
};

template <typename T>
class DynamicArray {
private:
    int totalCapacity;
    int size;
    T *arr;
    void expandCapacity(int index) {
        int newCapacity = index * 2 + 1;
        cout << "New Capacity: " << newCapacity << endl;
        T *newArr = new T[newCapacity];
        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        totalCapacity = newCapacity;
    }

public:
    DynamicArray(int initCapacity) : totalCapacity{initCapacity}, size{0} {
        arr = new T[initCapacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void add(int index, T value) {
        if (index < 0) {
            cout << "Index out of bounds" << endl;
            return;
        }
        if (index >= totalCapacity) {
            expandCapacity(index);
        }
        for (int i = size; i > index; --i) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
    }

    T get(int index) const {
        if (index < this->totalCapacity)
            return arr[index];
        else {
            cerr << "Error: Index out of bounds" << endl;
        }
    }

    bool operator<(const DynamicArray& a) {
        return this->size < a.size;
    }

    T operator[](int index) const {
        return get(index);
    }

    friend ostream& operator<<(ostream& out, const DynamicArray& arrArg) {
        for (int i = 0; i < arrArg.totalCapacity; i++) {
            out << arrArg[i] << " ";
        }
        out << endl;
        return out;
    }

    void clear() {
        this->size = 0;
    }
};

int main() {
    A a;
    DynamicArray<A*> aArray{5};
    aArray.add(0, new A(a));
   // cout << aArray;

    return 0;
}
