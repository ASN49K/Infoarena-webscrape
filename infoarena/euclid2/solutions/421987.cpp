#include <iostream.h>
#include <fstream.h>
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
int euclid (long int a,long int b)
{
 int m;
 while (a>0)
       {
            m=b%a; 
            b=a; 
            a=m; 
       }
 return b;     
}
int main()
{
 long int a,b;
 int n,i;
 f>>n;
 for (i=1;i<=n;++i)
     {
      f>>a>>b;
      g<<euclid(a,b)<<endl; 
     }           
 g.close();
 f.close();
 return 0;   
}
