#include<fstream.h>
int main()
{
 int n,i,a,b;
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 f>>n;
 for(i=1;i<=n;i++)
  {
   f>>a>>b;
   while(a!=b)
    if(a>b)
     a=a-b;
      else
       b=b-a;
   g<<a<<"\n";
  }
 return 0;
}