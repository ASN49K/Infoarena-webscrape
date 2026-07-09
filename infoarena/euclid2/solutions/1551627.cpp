#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,c,a,b,aux;
int main()
{
f>>t;
for(c=1;c<=t;c++)
    {
     f>>a>>b;
     while(b!=0)
     {
         aux=b;
         b=a%b;
         a=aux;
     }
     g<<a<<"\n";
    }
    return 0;
}
