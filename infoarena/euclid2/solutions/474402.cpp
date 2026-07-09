#include <iostream.h>
#include <fstream.h>

main()
{
      int t,a,b,r,i;
      ifstream f("eucli2.in");
      ofstream g("euclid2.out");
      
      f>>t;
      
      for(i=1;i<=t;i++)
      {
            f>>a>>b;
            while(r)
            {
                    r=b%a;
                    b=a;
                    a=r;
            }
            g<<b<<endl;
      }
      f.close();
      g.close();
}
      
