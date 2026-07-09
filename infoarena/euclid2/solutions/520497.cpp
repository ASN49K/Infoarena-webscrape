#include<fstream.h>
int main()
{int T,a,b,i=1;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>T;
for(i=1;i<=T;i++)
{f>>a>>b;
 while(b)
 {int r=a%b;
  a=b;
  b=r;
 }
 g<<a<<"\n";
}
return 0;
}