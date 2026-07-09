#include<fstream.h>
#include<iostream.h>
int main(void)
{
  fstream f,g;
  long int a,b,t,i;
  f.open("euclid2.in",ios::in);
  f>>t;
  g.open("euclid2.out",ios::out);
  for(i=1;i<=t;i++)
  {
    f>>a>>b;
    while(a!=b&&a%b!=0&&b%a!=0)
    {
      if(a>b)
	a=a%b;
      else
	b=b%a;
    }
    if(a!=b)
      if(a>b)
	g<<b;
      else
	g<<a;
    if(a==b)
    g<<a;
    g<<"\n";
  }
  f.close();
  g.close();
  return 0;
}