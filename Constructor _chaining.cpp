#include <iostream>
using namespace std;
class customer{
    string name;
    string address;
    int panno;
    int aadharno;
    long phone;
    string email;
    public:
    customer(string n,string a,int pno,int ano):name{n},address{a},panno{pno},aadharno{ano}
    {
         cout<<"inside cons1"<<endl;
    }
    //deligating constructor
    customer(string n,string a,int pno,int ano,long p):customer(n,a,pno,ano)
    {
        phone=p;
        cout<<"inside cons2"<<endl;
    }
    customer(string n,string a,int pno,int ano,string e):customer(n,a,pno,ano)
    {
        cout<<"inside cons3"<<endl;
        email=e;
    }
   
    customer(string n,string a,int pno,int ano,long p,string e):customer(n,a,pno,ano,p)
    {
        cout<<"inside cons4"<<endl;
        email=e;
    }
};
int main() {
    // Write C++ code here
    
    customer c("keerthi","asahbjaj",7896888,2345699,3416789,"arudhjh");

    return 0;
}
