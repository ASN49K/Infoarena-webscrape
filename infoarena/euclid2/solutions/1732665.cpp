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
        while(a!=b)
        {
            if(a>b)
            {
                a=a-b;
            }
            if(b>a)
            {
                b=b-a;
            }


        }
         if(a==b)
            {
                g<<a;
            }

        g<<"\n";
    }
    g.close();
    f.close();
    return 0;
}
