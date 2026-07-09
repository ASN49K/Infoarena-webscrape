#include <iostream.h>
#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{ long t,a,b,r;
      f>>t;
      for(long i=1;i<=t;i++)
      {
               f>>a>>b;
               while (b)
               {
                     r=a%b;
                     a=b;
                     b=r;
                     }
                 g<<a<<endl;                
                    }
      g.close();
}
