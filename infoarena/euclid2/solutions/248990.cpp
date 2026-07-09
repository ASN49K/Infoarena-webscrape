#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,a,b,x,i;
 int main()
{
 f>>n;
 for(i=1;i<=n;i++)
  { f>>a>>b;
  while(b!=0)
   if(b==0) g<<a;
    else
     {
      x=a;
      a=b;
      b=x%b;
     }

  g<<a<<"\n";
  }

 return 0;   
 }