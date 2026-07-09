#include<iostream.h>
#include<fstream.h>
void main(void)
{
long int i,r,e,a,t,b;
ifstream f;
ofstream g;
f.open("euclid2.in");
g.open("euclid2.out");
f>>t;
for(i=1;i<=t;i++){
 f>>a;
 f>>b;
 if(a<2) a=2;
if(b<0) b=-b;
 if(t<1) t=1;
  else if(t>100000) t=100000;
 while(a%b!=0) {
  r=a%b;
  a=b;
  b=r;}
 g<<b<<"\n";}
f.close();
g.close();
}