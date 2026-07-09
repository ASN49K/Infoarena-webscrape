#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

int euclid(int a, int b)
 {
   while (a!=0&&b!=0)
        if (a>b) a%=b;
           else  b%=a;
   return (a=0) ? a:b;

 }
int main()
{
   ifstream f("euclid2.in");
   ofstream g("euclid2.out");
    int T,a,b;

    f>>T;
    for(T=1;T<=3;T++)
     {
       f>>a;
       f>>b;
       g<<euclid(a,b)<<"\n";

     }

   return 0;
}
