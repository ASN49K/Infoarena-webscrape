#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int euclid(int a, int b)
 {
   while (a!=0&&b!=0)
        if (a>b) a%=b;
           else  b%=a;
   return (a+b);

 }
int main()
{
   ifstream f("euclid2.in");
   ofstream g("euclid2.out");
    int T,a,b;

    f>>T;
    for(int i=1;i<=T;i++)
     {
       f>>a;
       f>>b;
       g<<euclid(a,b)<<"\n";

     }
    f.close();
    g.close();

   return 0;
}
