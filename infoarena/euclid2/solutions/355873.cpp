#include<fstream.h>
 int cmmdc(int a,int b)
 {
   int r;
    while(b)
  {
    r=a%b;
    a=b;
    b=r;
  }
  return a;
 }


int main()
{
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  int a,b,n,i;
  f>>n;
  for(i=1;i<=n;i++)
  {
    f>>a>>b;
    g<<cmmdc(a,b)<<'\n';
  }
  f.close();
  g.close();
  return 0;
}