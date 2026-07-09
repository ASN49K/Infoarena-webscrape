#include<fstream.h>

ifstream f("euclid2.in");
ofstream g("euclid2.out");

unsigned long cmmdc(unsigned long a,unsigned long b)
{
if(!b) return a;
return cmmdc(b,a%b);
}

int main()
{
 unsigned long n,a,b,i;
 f>>n;
 for(i=0;i<n;i++)
 {
  f>>a>>b;
  g<<cmmdc(a,b)<<"\n";

 }
 return 0;
}