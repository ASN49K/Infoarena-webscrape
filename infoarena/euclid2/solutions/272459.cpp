#include<fstream.h>
int main ()
{
 
unsigned long t,a,b,r,i;
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
f>>t;
for(i=1;i<=t;i++)
 {
 f>>a>>b;
  do
   {
   r=a%b;
   a=b;
   b=r;
   }
  while(r);
 g<<a<<'\n';
 }
 f.close();
 g.close();
return 0;
}
