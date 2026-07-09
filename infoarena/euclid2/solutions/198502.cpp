#include<fstream.h>
#include<iostream.h>
int main()
{fstream f("euclid2.in",ios::in);
 fstream g("euclid2.out",ios::out);
 int t;
 f>>t;
 int a,b,r;
 while (t)
 {f>>a>>b;
  do {r=a%b;
     a=b;
     b=r;}
  while (r!=0);
  g<<a<<endl;
  t--;}
 f.close();
 g.close();
 return 0;
}