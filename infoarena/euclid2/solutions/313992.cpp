#include<fstream.h>
int main()
{
 int n,i,d,a,b;
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 f>>n;
 for(i=1;i<=n;i++)
  {
   f>>a>>b;
   d=a%b;
   while(d!=0)
    {
     a=b;b=d;
     d=a%b;
    }
   g<<b<<"\n";
  }
 return 0;
}