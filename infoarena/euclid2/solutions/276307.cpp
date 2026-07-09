#include<fstream.h>
int main ()
{
int i; 
long t,a,b,r;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
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
 g<<a<<"\n";
 }
f.close();
g.close();
return 0;
}