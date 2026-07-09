#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    int n,a,b,r=1,i,aux;
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");
    f>>n;
    for(i=0;i<n;i++)
    {
        f>>a>>b;
        if(a<b)
        {
         aux=a;
         a=b;
         b=aux;
        }
        r=1;
      while(r!=0)
      {
            r=a%b;
            a=b;
            b=r;
      }
      g<<a<<"\n";
    }
    return 0;
}
