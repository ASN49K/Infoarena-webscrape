#include <fstream.h>
int main ()
{int T,a,b,r,cmmdc,i;
ifstream f("flori.in") ;
ofstream g("flori.out") ;
do
  {
  r=a%b;
  a=b;
  b=r;
  }
while(r!=0);
cmmdc=a; 
f>>T;
for(i=1;i<=T;i++)
  {
  f>>a>>b;
  g<<cmmdc<<endl;
  }
f.close();
g.close();
return 0;
}