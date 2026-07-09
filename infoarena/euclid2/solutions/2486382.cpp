#include <iostream>
#include<fstream>
using namespace std;
ifstream f("euclid.in");
ofstream g("euclid.out");
int cmmdc(int a,int b)
{
   while(b)
   {
       int c=a%b;
       a=b;
       b=c;
   }
   return a;
}
int main()
{ int a,b,n;
f>>n;
for(int i=1;i<=n;i++)
{f>>a>>b;
g<<cmmdc(a,b)<<"\n";}

    return 0;
}
