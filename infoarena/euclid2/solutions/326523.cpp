#include<fstream.h>
#include<iostream.h>
int main()
{
 long int t,a,b,r,i;
 fstream f("euclid.in",ios::in);
 fstream g("euclid.out",ios::out);
 f>>t;
 for(i=0;i<t;i++)
 {
  f>>a>>b;
  while(b!=a)
  {
   r=a%b;
   a=b;
   b=r;
  }
  g<<a<<endl;
 }
 return 0;
}

