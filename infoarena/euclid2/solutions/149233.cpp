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
 g<<a<<'\n';
 g.close();
return 0;
}
