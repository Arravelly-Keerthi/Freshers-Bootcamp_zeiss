#include <iostream>
#include <string>

using namespace std;

class IPrinter {
public:
    virtual void print(string path) = 0;
};

class IScanner {
public:
    virtual void scan(string path) = 0;
};

class Printer : public IPrinter {
public:
    void print(string path) override {
        cout << "Printing ..... " << path;
    }
};

class Scanner : public IScanner {
public:
    void scan(string path) override {
        cout << "Scanning ..... " << path;
    }
};

class PrintScanner:public IPrinter,public IScanner {
    Printer P;
    Scanner S;

public:
    void print(string path)  {
        P.print(path);
    }

    void scan(string path) {
        S.scan(path);
    }
};

class TaskManager {
public:
    static void executePrintTask(IPrinter *device, string documentPath) {
        device->print(documentPath);
    }

    static void executeScanTask(IScanner *device, string documentPath) {
        device->scan(documentPath);
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
