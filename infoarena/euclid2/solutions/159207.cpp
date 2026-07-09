#include<fstream.h>
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");

  int euclid(int a,int b)
  {int r;

  while(a%b)
  {      r=a%b;
  a=b;
  b=r;
  }
  return b;
  }
int main()
{   int n,a,b;

 f>>n;


for(int i=1;i<=n;i++)
{f>>a>>b;
 g<<euclid(a,b)<<endl;}



 return 0;
}