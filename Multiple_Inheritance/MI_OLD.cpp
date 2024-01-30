#include <iostream>
#include <string>

using namespace std;

class IDevice {
public:
    virtual void doTask(string id) = 0;
};

class Printer : public IDevice {
public:
    void doTask(string path) override {
        cout << "Printing ..... " << path << endl;
    }
};

class Scanner : public IDevice {
public:
    void doTask(string path) override {
        cout << "Scanning ..... " << path;
    }
};

class PrintScanner : public IDevice {
public:
    void doTask(string path) override {
        cout << "Printing and Scanning ..... " << path;
    }
};

class TaskManager {
public:
    static void executePrintTask(IDevice *device, string documentPath) {
        device->doTask(documentPath);
    }

    static void executeScanTask(IDevice *device, string documentPath) {
        device->doTask(documentPath);
    }
};

int main() {
    Printer printerObj;
    Scanner scannerObj;
    PrintScanner printScannerObj;

    TaskManager::executePrintTask(&printerObj, "Test.doc");
    TaskManager::executeScanTask(&scannerObj, "MyImage.png");
    TaskManager::executePrintTask(&printScannerObj, "NewDoc.doc");
    TaskManager::executeScanTask(&printScannerObj, "YourImage.png");

    return 0;
}
