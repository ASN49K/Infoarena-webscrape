#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,r,T;
int main()
{f>>T;
for(;T;--T)
{f>>a>>b;
 while(b)
 {r=a%b;
  a=b;
  b=r;
 }
 g<<a<<"\n";
}
return 0;
}