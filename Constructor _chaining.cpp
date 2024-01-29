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
-------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

class Customer {
    string name;
    string address;
    int panno;
    int aadharno;
    long phone;
    string email;

public:
    Customer(string n, string a, int pno, int ano) : name{n}, address{a}, panno{pno}, aadharno{ano}, phone{0}, email{""} {
        cout << "inside customer cons" << endl;
    }

    void setPhone(long p) {
        phone = p;
    }

    void setEmail(string e) {
        email = e;
    }

    string getName() const {
        return name;
    }
    int getphone()
    {
        return phone;
    }
    string getemail()
    {
        return email;
    }
};

class CustomerBuilder {
    Customer* customer;

public:
    CustomerBuilder(string n, string a, int pno, int ano)
        : customer(new Customer(n, a, pno, ano)) {}

    CustomerBuilder* setPhone(long p) {
        customer->setPhone(p);
        return this;
    }

    CustomerBuilder* setEmail(string e) {
        customer->setEmail(e);
        return this;
    }

    Customer* getInstance() {
        return customer;
    }
};

int main() {
    Customer* c = (new CustomerBuilder{"keerthi", "atfgh", 567899, 56780091})->getInstance();
    cout << c->getName() << endl;
    Customer* c1 = (new CustomerBuilder{"keerthi", "atfgh", 567899, 56780091})->setPhone(1234567890)->getInstance();
    cout << c1->getphone() << endl;
    Customer* c2 = (new CustomerBuilder{"keerthi", "atfgh", 567899, 56780091})->setPhone(1234567890)->setEmail("keerthi@example.com")->getInstance();
  cout << c2->getemail() << endl;

    delete c; 

    return 0;
}

