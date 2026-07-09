#include <iostream>
#include <fstream>
using namespace std;
int a,b,t,n,celmaimare;
int main()
{
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
   f>>t;
   for(int i=0;i<t;i++)
    {
        f>>a;
        f>>b;
        if(a>b)
        {
            n=b;
        }
        else
        {
            n=a;
        }
        for(int w=1;w<=n;w++)
        {
            if(a%w==0&&b%w==0)
            {
                celmaimare=w;
            }
        }
        g<<celmaimare<<"\n";
    }
    g.close();
    f.close();
    return 0;
}
