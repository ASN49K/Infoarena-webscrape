#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,r;
int main()
{f>>a;
 f>>b;
 f.close();
 do
  {r=a%b;
   a=b;
   b=r;
  }
 while(r);
 if(a==1) {g<<0<<'\n'; g.close(); return 0;}
 g<<a<<'\n';
 g.close();
return 0;
}
