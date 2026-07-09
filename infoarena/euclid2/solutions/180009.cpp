#include<fstream.h>
#include<iostream.h>
int main()
{
  fstream f,g;
  long int a,b,t,i;
  f.open("euclid2.in",ios::in);
  f>>t;
  g.open("euclid2.out",ios::out);
  for(i=1;i<=t;i++)
  {
    f>>a>>b;
    while(a!=b)
    {
      if(a>b)
	a=a%b;
      else
	b=b%a;
    }
    g<<a;
    g<<"\n";
  }
  f.close();
  g.close();
  return 0;
}