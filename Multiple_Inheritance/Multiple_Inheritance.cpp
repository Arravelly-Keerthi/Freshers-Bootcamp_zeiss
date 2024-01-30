#include<iostream>
#include<string>
using namespace std;
class Device{
    string id;
    protected:
   Device()
   {cout<<"Device Constructor "<<endl;};
     Device(string s):id(s){};
     public:
    string getDeviceId(){return id;}
    ~Device(){
        cout<<"Device Destructor"<<endl;
    }
};
 class Printer:virtual public Device{
    public:
    
    //Printer(){};
    Printer(){
        cout<<"Printer Constructer";
    }
     Printer(string s):Device::Device(s){};
     
    ~Printer(){
        cout<<"Printer Destructor "<<endl;
    }
     void print(string path){
        cout<<"Printing ....."<<path;
    }
};

class Scanner:virtual public Device{

    public:
    Scanner(){cout<<"Scanner Constructer";}
     Scanner(string s):Device::Device{s}{};
//   Scanner(){
//         cout<<"Scanner Constructor "<<endl;
//     }
    ~Scanner(){
        cout<<"Scanner Destructor "<<endl;
    }
     void scan(string path){
        cout<<"Scanning ....."<<path;
    }
};


 class TaskManager{
    public:
    //this method doesnt need an argument called this
     TaskManager(){
        cout<<"TaskManager Constructor "<<endl;
    }
    ~TaskManager(){
        cout<<"TaskManager Destructor "<<endl;
    }
     static void execuctePrintTask(Printer *printer,string documentPath){
        printer->print(documentPath);
    }
     static void execucteScanTask(Scanner *scanner,string documentPath){
            scanner->scan(documentPath);
    }
};
 class PrinterScanner :public Printer,public Scanner {
     public:
   PrinterScanner(string s):Device::Device{s}{};
     //PrinterScanner(){
    //    cout<<"PrinterScanner Constructor "<<endl;
    // }
    ~PrinterScanner(){
        cout<<"PrinterScanner Destructor "<<endl;
    }
};

    int main(){
        //Printer printerObj("102");
        //Scanner scannerObj("189");
        PrinterScanner printScannerObj("123");

        //TaskManager::execuctePrintTask(&printerObj,"Test.doc");
        //TaskManager::execucteScanTask(&scannerObj,"MyImage.png");
        TaskManager::execuctePrintTask(&printScannerObj,"NewDoc.doc");
        TaskManager::execucteScanTask(&printScannerObj,"YourImage.png");
    }
