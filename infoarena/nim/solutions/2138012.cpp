#include <iostream>
#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int i,t,xors,n,j,x;
int main()
{
   f>>t;
   for(i=1;i<=t;i++)
   {
       f>>n;
       xors=0;
       for(j=1;j<=n;j++)
       {
           f>>x;
           xors=xors ^ x;
       }
       if(xors>0)
        g<<"DA"<<endl;
       else
        g<<"NU"<<endl;
   }
}
