#include<fstream.h>
unsigned long cmmdc(unsigned long a,unsigned long b)
{unsigned long r;
do
 {r=a%b;
  a=b;
  b=r;
 }
while(r);
return a;
}
int main()
{ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned long t,i,x,y,c;
f>>t;
for(i=1;i<=t;i++)
 {f>>x>>y;
  c=cmmdc(x,y);
  g<<c<<'\n';
 }
f.close();
g.close();
return 0;
}