#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");

int Cmmdc(int a,int b)
{ int c;
    while(b)
    { c=a%b;
      a=b; b=c;
    }
  return a;
}

int main()
{ int n,i,x,y;
   f>>n;

   for(i=1;i<=n;i++)
   { f>>x>>y;
      g<<Cmmdc(x,y)<<"\n";
   }
    return 0;
}
