// Online C++ compiler to run C++ program online
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
    customer(string n,string a,int pno,int ano)
    {
         cout<<"inside cons1"<<endl;
        name=n;
        address=a;
        panno=pno;
        aadharno=ano;
    }
    customer(string n,string a,int pno,int ano,long p)
    {
        cout<<"inside cons2"<<endl;
        name=n;
        address=a;
        panno=pno;
        aadharno=ano;
        phone=p;
    }
    customer(string n,string a,int pno,int ano,string e)
    {
        cout<<"inside cons3"<<endl;
        name=n;
        address=a;
        panno=pno;
        aadharno=ano;
        //phone=p;
        email=e;
    }
   
    customer(string n,string a,int pno,int ano,long p,string e)
    {
        cout<<"inside cons4"<<endl;
        name=n;
        address=a;
        panno=pno;
        aadharno=ano;
        phone=p;
        email=e;
    }
};
int main() {
    // Write C++ code here
    
    customer c("keerthi","asahbjaj",7896888,2345699,3416789,"arudhjh");

    return 0;
}
