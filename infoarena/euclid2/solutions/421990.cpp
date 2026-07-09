#include <iostream.h>
#include <fstream.h>
 
using namespace std;
/*int euclid (long int a,long int b)
{
 int m;
 while (a>0)
       {
            m=b%a; 
            b=a; 
            a=m; 
       }
 return b;     
}*/
int main()
{
 long a,b,r;
 int n,i;
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 f>>n;
 for (i=1;i<=n;i++)
     {
      f>>a>>b;
      r=a%b;
       while (r)
        {
            a=b;
            b=r;
            r=a%b;
        }
      g<<b<<endl; 
     }           
 g.close();
 f.close();
 return 0;   
}
