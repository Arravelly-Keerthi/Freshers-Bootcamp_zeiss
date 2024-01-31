#include <iostream>
//const ,reference (&((Locator value )LValue Reference),&&(Rvalue Reference))
using namespace std;
class A{
    public:
    A(){
        cout<<"A's constructor "<<" ";
    }
    ~A(){
        cout<<"A's destructor "<<" ";
    }
    void m(){}
};
void f(A &obj){
    
}
void f(const A &obj){
  //obj.x=100;
}
// void f(A *obj){
//     //for this object is created once
//     //but have to take care of the memory lekage 
//     //Concept of const correctness comes in picture
// }
// void f(A obj){
//     //for this object is created twice as it is passed as an value 
// }
int main() {
   int x=10;//adress 1000h?
   int *p=&x;//p at 3000h holding the adrress 1000h
   int &refx=x;//alias other name of x is refx
  // int &newRef;
//error: 'newRef' declared as reference but not initialized
refx=100;
cout<<x<<" "<<refx<<endl;
A source;
f(source);
    return 0;
}
