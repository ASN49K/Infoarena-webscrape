#include <fstream.h>

int main()
{
      ifstream f("euclid2.in");
      ofstream g("euclid2.out");
      
      int t,a,b,r,i;
      
      f>>t;
      
      for(i=1;i<=t;++i)
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
      return 0;
}
      
