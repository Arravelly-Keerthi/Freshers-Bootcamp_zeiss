// scope.cpp
// Accessing objects with equal names
// ---------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;
int var = 0;
namespace Special { int var = 100; }
int main()
{
   int var = 10;
   cout << setw(10) << var; // 1.Block Scope value 10
   {
   	int var = 20;
   	cout << setw(10) << var << endl; // 2.Block Scope value 20
   	{
   		++var;
   		cout << setw(10) << var; // 3.Block Scope value 21
   		cout << setw(10) << ++ ::var; // 4.Global variable File scope val 1
   		cout << setw(10) << Special::var * 2 // 5.Namespace  100*2
   			<< endl;
   	}
   	cout << setw(10) << var - ::var; // 6.Block Scope - GlobalScope (21-1)
   }
   cout << setw(10) << var << endl; // 7.Block Scope value 10
   return 0;
}

// OUTPUT:
// 10        20
//         21         1       200
//         20        10
