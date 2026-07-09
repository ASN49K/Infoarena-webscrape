#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc()
{
 long a,b,min,cmmdc=1,i;
 f>>a>>b;
 if(a>b) min=b; else min=a;
 if(a%min==0&&b%min==0)
  return min;
 else
  {for(i=2;i<min;i++)
    while(a%i==0&&b%i==0) {a/=i; b/=i; min/=i; cmmdc*=i;}
   return cmmdc;
  }
}
void main()
{
 int x,i;
 f>>x;
 for(i=1;i<=x;i++)
 g<<cmmdc()<<"\n";
}
