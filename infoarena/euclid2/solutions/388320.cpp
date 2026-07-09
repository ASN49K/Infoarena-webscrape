#include <iostream.h>
#include <fstream.h>
main()
{
int a,b,n,i;
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
f>>n;
 for(i=1;i<=n;i++)
  { f>>a>>b;
      while(a!=b)
        {
         if(a>b)
           a=a-b;
         else
           b=b-a;
        }
     if(a==1)
        g<<1<<"\n";
     else
        g<<a<<"\n";
  }
f.close();
g.close();
}




