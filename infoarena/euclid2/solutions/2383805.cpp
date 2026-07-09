#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T,i,a,b;
int main()
{int d;
   f>>T;
   for (i=1;i<=T;i++)
   {
       f>>a>>b;

       while (b!=0)
       {
           d=b;
           b=a%b;
           a=d;

       }
       g<<a<<'\n';
   }
}
