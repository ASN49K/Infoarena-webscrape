#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
          int a,b,n,i;

int cmmdc(int a,int b)
    {
               int r;
               while(b)
                       {
                            r=a%b;
                            a=b;
                            b=r;
                       }
               g<<a<<"\n";
               return 0;
    }

int main()
    {
          f>>n;
          for(i=1;i<=n;i++)
          {f>>a>>b;
          cmmdc(a,b);
          }
          return 0;
          f.close();
          g.close();
    
}
