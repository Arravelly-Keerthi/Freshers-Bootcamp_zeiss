#include <iostream>
#include <memory>
#include<bits/stdc++.h>
using namespace std;
// template <typename Res>
// void Sum(Res& result) {}


template < typename T, typename... Args>
auto Sum( T firstArg, Args... parameterPack)->decltype(firstArg)
{
   // result += val;
    //cout<<val<<endl;
   // (cout<<...<<args)<<endl;
   auto rangeofValues={firstArg,parameterPack...};
   //cout<<res<<" ";
  decltype(firstArg)  result;
   for(auto x: rangeofValues)
     result+=x;
   // accumulate(rangeofValues.begin(),rangeofValues.end(),0);
       return result;
}

int main()
{
    int intResult ;
   intResult= Sum( 1, 2, 3);
    cout  << intResult << endl;

    double doubleResult ;
    doubleResult=Sum( 5.7, 8.1, 9.7, 35.1, 67.9, 89.7, 12.5);
    cout << doubleResult << endl;

    return 0;
}
