# include <iostream.h>
# include <fstream.h>
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
int main ()
{
 int a,b,r,t,i;
 f>>t;
 for (i=1;i<=t;i++) {
 f>>a>>b;
  do {
  r=a%b;
  a=b;
  b=r;
  } while (r!=0);
  g<<a<<"\n";
  }
  f.close();
  g.close();

 return 0;
 }
