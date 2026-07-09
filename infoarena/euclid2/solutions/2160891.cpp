#include <iostream>
#include <fstream>
using namespace std;

int main()
{
 int T, a, b, r ;
 ifstream f("euclid2.in");
 ofstream o("euclid2.out");
 f >> T;
 if(1<=T && T<=100000 )
 {
     while(!T==0)
     {
         f >> a >> b;
         if(2<=a && b<=2*10*10*10*10*10*10*10*10*10)
         { while(!b==0)
          {
             r=a%b;
             a=b;
             b=r;
          }
           o << a << "\n";
         }
         T--;
     }
 }
 f.close();
 o.close();
 }
