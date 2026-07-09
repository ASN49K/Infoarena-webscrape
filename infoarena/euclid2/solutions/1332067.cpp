#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
ifstream f("parantezare.in");
ofstream g("parantezare.out");

int main()
{

    int a,b,d,i,T;
    f>>T;

    for(i=0;i<T;i++)
    {
    f>>a>>b;
    while(b!=0)
    {
      d=b;
      b=a%d;
      a=d;
    }
     g<<a<<"\n";
    }


    return 0;
}


