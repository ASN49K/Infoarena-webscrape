#include <iostream.h>
#include<fstream.h>

ifstream f("euclid.in");
ofstream g("euclid.out");


long t, a,b;

main()
{
      f>>t;
      for(long i=1;i<=t;i++)
      {
               f>>a>>b;
               int r,opt;
               while (b)
               {
                     r=a%b;
                     a=b;
                     b=r;
                     }
                     if(a>1) g<<a<<endl;
                     else g<<'1';}
      g.close();
}
