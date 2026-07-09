#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   ifstream f("euclid2.in");
   ofstream g("euclid2.out");
   int a, b, t, i, d;
   f >> t;
   for(i=1;i<=t;i++)
   {
       f >> a >> b;
       while(b!=0)
       {
           d=a%b;
           a=b;
           b=d;
       }
       g << a << endl;
   }
   return 0;
}
