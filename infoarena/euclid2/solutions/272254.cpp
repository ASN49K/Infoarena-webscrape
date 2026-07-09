#include<fstream.h>
void main ()
{
int i; 
unsigned long t,a,b,r;
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
 g<<a<<endl;
 }
}