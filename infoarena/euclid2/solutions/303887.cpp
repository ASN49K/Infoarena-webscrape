#include<fstream.h>
long x,y,t,i;
long cmmdc(long a, long b)
{
 while(a!=b)
 {
  while(a>b)
	a-=b;
  while(b>a)
	b-=a;
 }
 return a;
}
int main()
{
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");

 f>>t;
 for(i=1;i<=t;i++)
 {
  f>>x>>y;
  g<<cmmdc(x,y)<<'\n';
 }


 f.close();
 g.close();
 return 0;
}