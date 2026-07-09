#include<fstream.h>

 ifstream f("euclid2.in");
 ofstream g("euclid2.out");


int main()
{
 long a,b,r,n,i;
 f>>n;
 for(i=1;i<=n;i++)
 {
 f>>a;
 f>>b;

 r=a%b;
 while(r)
 {
   a=b;
   b=r;
   r=a%b;
   }
 g<<b<<"\n";}
 f.close();
 g.close();
 return 0;
}