#include <iostream>
#include<vector>
//
using namespace std;
class A{
    public:
    ~A(){
        cout<<"A Destructor "<<endl;
    }
    void method(){
        cout<<"A's method "<<endl;
    }
};
class B{
    public:
    ~B(){
        cout<<"B Destructor "<<endl;
    }
};
template<typename T>
class SmartPointerTypeForA{
  T* rawPtr;
  public:
   SmartPointerTypeForA(T *ptr):rawPtr(ptr){}
   ~SmartPointerTypeForA(){
       delete rawPtr;
   }
   T* operator->() const {
		return rawPtr;
	}
};


void init()
{
    SmartPointerTypeForA sp{new A()};
    sp->method();
    SmartPointerTypeForA sp1{new B()};
}
int main(){
    init();
    return 0;
}
