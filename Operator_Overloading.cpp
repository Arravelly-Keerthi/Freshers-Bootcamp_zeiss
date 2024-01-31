#include <iostream>
using namespace std;

class DynamicIntegerArray {
    int size;
    int* array;

public:
    DynamicIntegerArray(int max) : size(max) {
        array = new int[size];
    }

    ~DynamicIntegerArray() {
        delete[] array;
    }

    void add(int i, int val) {
        if (i < size)
            array[i] = val;
        else {
            int* newarray = new int[2 * size];
            cout<<"Numbers Array resized to "<<2*size<<endl;
            for (int j = 0; j < size; j++)
                newarray[j] = array[j];
            newarray[i] = val;
            delete[] array;
            array = newarray;
            size *= 2;  
        }
    }

    int get(int i) const {
        return array[i];
    }

    void clear() {
        delete[] array;
        size = 0;  
        array = new int[size];
    }

    bool operator>(const DynamicIntegerArray& d) const {
        return size > d.size;
    }

    int& operator[](int i) {
        if (i < 0 || i >= size) {
            cout << "\nDynamicIntegerArray: Outside of range!" << endl;
            exit(1);
        }
        return array[i];
    }

    friend ostream& operator<<(ostream& out, const DynamicIntegerArray& s) {
        for (int i = 0; i < s.size; i++) {
            out << s.get(i) << " ";
        }
        out << endl;
        return out;
    }
};

int main() {
    DynamicIntegerArray numbers{3};
    DynamicIntegerArray newnumbers{5};
    numbers.add(0, 10);
    numbers.add(1, 13);
    numbers.add(2, 14);
    numbers.add(3, 15);
    int value = numbers[2];
    cout << value << endl;
    cout << numbers;

    if (numbers > newnumbers) {
        cout << "Numbers array contains more elements than newnumbers array" << endl;
    }

    cout << numbers[3] << endl;
    numbers.clear();

    return 0;
}
